#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <stdio.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>

struct rootfs {
	char *dev;
	int flags;
};

int get_rootfs(struct rootfs *root)
{
	int fd;
	ssize_t len;
	char buf[1024];

	root->dev = NULL;
	root->flags = 0;

	fd = open("/proc/cmdline", O_RDONLY);
	if (fd < 0) {
		return -1;
	}

	len = read(fd, buf, sizeof(buf) - 1);
	if (len < 0) {
		close(fd);
		return -1;
	}
	buf[len] = '\0';
	close(fd);

	// Read cmdline by words
	// not using strtok
	char *p = buf;
	while (*p) {
		while (*p == ' ')
			p++;

		if (*p == '\0')
			break;

		char *start = p;
		while (*p && *p != ' ')
			p++;
		size_t word_len = p - start;

		if (strncmp(start, "root=", 5) == 0) {
			size_t dev_len = word_len - 5;
			root->dev = strndup(start + 5, dev_len);
		} else if (strncmp(start, "ro", 2) == 0) {
			root->flags |= MS_RDONLY;
		} else if (strncmp(start, "rw", 2) == 0) {
			root->flags &= ~MS_RDONLY;
		}
	}

	return 0;
}

int main(void)
{
	struct rootfs root;
	char *const argv[] = { "/bin/init", NULL };

	if (mkdir("/dev", 0755) < 0 && errno != EEXIST) {
		perror("mkdir /dev");
		return -1;
	}

	if (mount("devtmpfs", "/dev", "devtmpfs", 0, NULL) < 0) {
		perror("mount devtmpfs");
		return -1;
	}

	if (mkdir("/proc", 0755) < 0 && errno != EEXIST) {
		perror("mkdir /proc");
		return -1;
	}

	if (mount("proc", "/proc", "proc", 0, NULL) < 0) {
		perror("mount proc");
		return -1;
	}

	/* Get root filesystem info from kernel cmdline */
	if (get_rootfs(&root) < 0) {
		err(1, "init: get rootfs info");
	}

	if (mount(root.dev, "/root", "ext4", root.flags, NULL) < 0)
		err(1, "init: mount rootfs %s", root.dev);

	if (mkdir("/root/dev", 0755) < 0)
		err(1, "init: mkdir /root/dev");

	if (mount("/dev", "/root/dev", NULL, MS_BIND | MS_REC, NULL) < 0)
		err(1, "init: mount --bind /dev");

	if (mkdir("/root/proc", 0755) < 0)
		err(1, "init: chdir /root");

	if (mount("/proc", "/root/proc", NULL, MS_BIND | MS_REC, NULL) < 0)
		err(1, "init: mount --bind /proc");

	if (mkdir("/root/sys", 0755) < 0)
		err(1, "init: chdir /root");

	if (mount("sysfs", "/root/sys", "sysfs", 0, NULL) < 0)
		err(1, "init: mount --bind /sys");

	if (chroot("/root") < 0)
		err(1, "init: chroot /root");

	if (chdir("/") < 0)
		err(1, "init: chdir /");

	execve("/bin/init", argv, NULL);
	err(1, "init: execve /bin/init");
}
