#include "stddef.h" // for NULL

#include <atomic.h> // for LIBC_LOCK, LIBC_UNLOCK
#include <libc.h>   // for libc, libc::(anonymous), libc::LIBC_ENVP_TOUCHED
#include <stdlib.h> // for malloc, realloc, setenv
#include <string.h> // for strlen, size_t, memcpy, strcpy, strchr, strncmp

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
				strcpy(new_env, var);
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

	char **new_envp = (char **)realloc((void *)environ,
					   (env_count + 2) * sizeof(char *));
	if (!new_envp)
		return -1;

	size_t value_len = strlen(value);
	char *new_var = malloc(var_len + 1 + value_len + 1);
	if (!new_var)
		return -1;

	strcpy(new_var, var);
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
