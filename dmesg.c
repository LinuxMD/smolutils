// SPDX-License-Identifier: GPL-3.0-or-later

#define CONSOLE_EXT_LOG_MAX 8192

int main (int argc, char **argv, char **envp)
{
	char buf[CONSOLE_EXT_LOG_MAX + 1] = { 0 };
	int len;
	int fd;

	fd = open("/dev/kmsg", O_RDONLY | O_NONBLOCK);
	if (fd < 0)
		return 1;

	while (true) {
		len = read(fd, buf, CONSOLE_EXT_LOG_MAX);
		if(len < 0)
			break;
		fputs(buf, stdout);

		memset(buf, 0, len);
	}

	close(fd);

	return 0;
}
