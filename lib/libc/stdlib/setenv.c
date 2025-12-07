#include <libc.h>
#include <atomic.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int setenv(const char *var, const char *value, int overwrite)
{
	char **env = environ;
	size_t var_len = strlen(var);

	for (; *env; env++) {
		char *eq = strchr(*env, '=');
		if (eq && ((size_t)(eq - *env) == var_len) &&
		    !strncmp(*env, var, var_len)) {
			if (overwrite) {
				size_t value_len = strlen(value);
				char *new_env =
					malloc(var_len + 1 + value_len + 1);
				if (!new_env)
					return -1;
				memcpy(new_env, var, var_len);
				new_env[var_len] = '=';
				memcpy(new_env + var_len + 1, value,
				       value_len + 1);
				*env = new_env;
			}
			return 0;
		}
	}

	size_t env_count = 0;
	while (environ[env_count])
		env_count++;

	char **new_envp = realloc(environ, (env_count + 2) * sizeof(char *));
	if (!new_envp)
		return -1;

	size_t value_len = strlen(value);
	char *new_var = malloc(var_len + 1 + value_len + 1);
	if (!new_var)
		return -1;

	memcpy(new_var, var, var_len);
	new_var[var_len] = '=';
	memcpy(new_var + var_len + 1, value, value_len + 1);

	new_envp[env_count] = new_var;
	new_envp[env_count + 1] = NULL;
	LIBC_LOCK(libc.lock.environ);
	environ = new_envp;
	LIBC_UNLOCK(libc.lock.environ);
	libc.flags |= LIBC_ENVP_TOUCHED;

	return 0;
}
