// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef _SMOLUTILS_NET_H
#define _SMOLUTILS_NET_H

static int smolutils_net_setsockbroadcast(int sock)
{
	int sock_opt = 1;
	int ret;

	ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST,
			 &sock_opt, sizeof(sock_opt));
	if (ret < 0) {
		error("Failed to set broadcast\n");
		return -1;
	}

	return 0;
}

static int smolutils_net_setsockrxtimeout(int sock, int timeout)
{
	struct timeval tv = { .tv_sec = timeout };
	int ret;

	ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	if (ret) {
		verbose("Failed to set socket timeout\n");
		return -1;
	}

	return 0;
}

#endif /* _SMOLUTILS_NET_H */
