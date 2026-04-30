// SPDX-License-Identifier: GPL-3.0-or-later

#include "config.h"
#include "common.h"

static int cb(const char *name, void *priv)
{
	printf("%s\n", name);

	return 0;
}

int main(int argc, char **argv, char **envp)
{
	char *path = ".";

	if (argc == 2)
		path = argv[1];

	iterate_dir(path, cb, NULL);

	return 0;
}
