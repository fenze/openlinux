#ifndef __NETDB_H
#define __NETDB_H

#include <stdint.h>
#define IPPORT_RESERVED 1024

#define AI_PASSIVE     0x00000001
#define AI_CANONNAME   0x00000002
#define AI_NUMERICHOST 0x00000004
#define AI_NUMERICSERV 0x00000008

#define AI_ALL	      0x00000100
#define AI_ADDRCONFIG 0x00000400
#define AI_V4MAPPED   0x00000800

#define NI_NOFQDN	0x00000001
#define NI_NUMERICHOST	0x00000002
#define NI_NAMEREQD	0x00000004
#define NI_NUMERICSERV	0x00000008
#define NI_DGRAM	0x00000010
#define NI_NUMERICSCOPE 0x00000100

#define EAI_AGAIN    2
#define EAI_BADFLAGS 3
#define EAI_FAIL     4
#define EAI_FAMILY   5
#define EAI_MEMORY   6
#define EAI_NONAME   8
#define EAI_SERVICE  9
#define EAI_SOCKTYPE 10
#define EAI_SYSTEM   11
#define EAI_OVERFLOW 14

typedef __INT32_TYPE__ socklen_t;
typedef __UINT32_TYPE__ uint32_t;

struct hostent {
	char *h_name;
	char **h_aliases;
	int h_addrtype;
	int h_length;
	char **h_addr_list;
};

struct netent {
	char *n_name;
	char **n_aliases;
	int n_addrtype;
	uint32_t n_net;
};

struct protoent {
	char *p_name;
	char **p_aliases;
	int p_proto;
};

struct servent {
	char *s_name;
	char **s_aliases;
	int s_port;
	char *s_proto;
};

struct addrinfo {
	int ai_flags;
	int ai_family;
	int ai_socktype;
	int ai_protocol;
	socklen_t ai_addrlen;
	struct sockaddr *ai_addr;
	char *ai_canonname;
	struct addrinfo *ai_next;
};

void endhostent(void);
void endnetent(void);
void endprotoent(void);
void endservent(void);
void freeaddrinfo(struct addrinfo *);
const char *gai_strerror(int);
int getaddrinfo(const char *restrict, const char *restrict, const struct addrinfo *restrict,
		struct addrinfo **restrict);
struct hostent *gethostent(void);
int getnameinfo(const struct sockaddr *restrict, socklen_t, char *restrict, socklen_t, char *restrict, socklen_t, int);
struct netent *getnetbyaddr(uint32_t, int);
struct netent *getnetbyname(const char *);
struct netent *getnetent(void);
struct protoent *getprotobyname(const char *);
struct protoent *getprotobynumber(int);
struct protoent *getprotoent(void);
struct servent *getservbyname(const char *, const char *);
struct servent *getservbyport(int, const char *);
struct servent *getservent(void);
void sethostent(int);
void setnetent(int);
void setprotoent(int);
void setservent(int);

#endif
