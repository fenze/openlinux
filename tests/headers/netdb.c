// https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/netdb.h.html

#include "core.h"

#include <netdb.h>

TEST(netdb_h)
{
	TYPE(struct hostent);
	STRUCT_MEMBER(struct hostent, char *, h_name);
	STRUCT_MEMBER(struct hostent, char **, h_aliases);
	STRUCT_MEMBER(struct hostent, int, h_addrtype);
	STRUCT_MEMBER(struct hostent, int, h_length);
	STRUCT_MEMBER(struct hostent, char **, h_addr_list);

	TYPE(struct netent);
	STRUCT_MEMBER(struct netent, char *, n_name);
	STRUCT_MEMBER(struct netent, char **, n_aliases);
	STRUCT_MEMBER(struct netent, int, n_addrtype);
	STRUCT_MEMBER(struct netent, uint32_t, n_net);

	TYPE(uint32_t);
	TYPE(struct protoent);
	STRUCT_MEMBER(struct protoent, char *, p_name);
	STRUCT_MEMBER(struct protoent, char **, p_aliases);
	STRUCT_MEMBER(struct protoent, int, p_proto);

	TYPE(struct servent);
	STRUCT_MEMBER(struct servent, char *, s_name);
	STRUCT_MEMBER(struct servent, char **, s_aliases);
	STRUCT_MEMBER(struct servent, int, s_port);
	STRUCT_MEMBER(struct servent, char *, s_proto);

	MACRO(IPPORT_RESERVED);

	TYPE(struct addrinfo);
	STRUCT_MEMBER(struct addrinfo, int, ai_flags);
	STRUCT_MEMBER(struct addrinfo, int, ai_family);
	STRUCT_MEMBER(struct addrinfo, int, ai_socktype);
	STRUCT_MEMBER(struct addrinfo, int, ai_protocol);
	STRUCT_MEMBER(struct addrinfo, socklen_t, ai_addrlen);
	STRUCT_MEMBER(struct addrinfo, struct sockaddr *, ai_addr);
	STRUCT_MEMBER(struct addrinfo, char *, ai_canonname);
	STRUCT_MEMBER(struct addrinfo, struct addrinfo *, ai_next);

	MACRO(AI_PASSIVE);
	MACRO(AI_CANONNAME);
	MACRO(AI_NUMERICHOST);
	MACRO(AI_NUMERICSERV);
	MACRO(AI_V4MAPPED);
	MACRO(AI_ALL);
	MACRO(AI_ADDRCONFIG);

	MACRO(NI_NOFQDN);
	MACRO(NI_NUMERICHOST);
	MACRO(NI_NAMEREQD);
	MACRO(NI_NUMERICSERV);
	MACRO(NI_NUMERICSCOPE);
	MACRO(NI_DGRAM);

	MACRO(EAI_AGAIN);
	MACRO(EAI_BADFLAGS);
	MACRO(EAI_FAIL);
	MACRO(EAI_FAMILY);
	MACRO(EAI_MEMORY);
	MACRO(EAI_NONAME);
	MACRO(EAI_SERVICE);
	MACRO(EAI_SOCKTYPE);
	MACRO(EAI_SYSTEM);
	MACRO(EAI_OVERFLOW);

	void endhostent(void);
	void endnetent(void);
	void endprotoent(void);
	void endservent(void);
	void freeaddrinfo(struct addrinfo *);
	const char *gai_strerror(int);
	int getaddrinfo(const char *restrict, const char *restrict,
			const struct addrinfo *restrict,
			struct addrinfo **restrict);
	struct hostent *gethostent(void);
	int getnameinfo(const struct sockaddr *restrict, socklen_t,
			char *restrict, socklen_t, char *restrict, socklen_t,
			int);
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

	FUNCTION(endhostent, FN(void, void));
	FUNCTION(endnetent, FN(void, void));
	FUNCTION(endprotoent, FN(void, void));
	FUNCTION(endservent, FN(void, void));
	FUNCTION(freeaddrinfo, FN(void, struct addrinfo *));
	FUNCTION(gai_strerror, FN(const char *, int));
	FUNCTION(getaddrinfo,
		 FN(int, const char *restrict, const char *restrict,
		    const struct addrinfo *restrict,
		    struct addrinfo **restrict));
	FUNCTION(gethostent, FN(struct hostent *, void));
	FUNCTION(getnameinfo,
		 FN(int, const struct sockaddr *restrict, socklen_t,
		    char *restrict, socklen_t, char *restrict, socklen_t, int));
	FUNCTION(getnetbyaddr, FN(struct netent *, uint32_t, int));
	FUNCTION(getnetbyname, FN(struct netent *, const char *));
	FUNCTION(getnetent, FN(struct netent *, void));
	FUNCTION(getprotobyname, FN(struct protoent *, const char *));
	FUNCTION(getprotobynumber, FN(struct protoent *, int));
	FUNCTION(getprotoent, FN(struct protoent *, void));
	FUNCTION(getservbyname,
		 FN(struct servent *, const char *, const char *));
	FUNCTION(getservbyport, FN(struct servent *, int, const char *));
	FUNCTION(getservent, FN(struct servent *, void));
	FUNCTION(sethostent, FN(void, int));
	FUNCTION(setnetent, FN(void, int));
	FUNCTION(setprotoent, FN(void, int));
	FUNCTION(setservent, FN(void, int));
}
