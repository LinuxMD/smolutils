// SPDX-License-Identifier: GPL-3.0-or-later

#include "config.h"
#include "common.h"

int main (int argc, char **argv, char **envp)
{
	const char *path;
	int ret;

	if (argc != 2)
		return 1;

	path = argv[1];

	ret = mkdir(path, 0755);
	if (ret) {
		error("mkdir() failed: %d\n", errno);
		return 1;
	}

	return 0;
}
