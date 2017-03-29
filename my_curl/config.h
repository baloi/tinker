#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef HAVE_STRCASECMP
#define strnequal(x,y,z) !strncasecmp(x,y,z)
#define strequal(x,y) !strcasecmp(x,y)
#else
#define strnequal(x,y,z) !strnicmp(x,y,z)
#define strequal(x,y) !stricmp(x,y)
#endif

/* Below we define three functions. They should
   1. close a socket
   2. read from a socket
   3. write to a socket
   Hopefully, only win32-crap do this weird name changing
   */

#ifdef WIN32
#define sclose(x) closesocket(x)
#define sread(x,y,z) recv(x,y,z,0)
#define swrite(x,y,z) (size_t)send(x,y,z,0)
#else
#define sclose(x) close(x)
#define sread(x,y,z) read(x,y,z)
#define swrite(x,y,z) write(x,y,z)
#ifdef HAVE_STRCASECMP
/* this is for "-ansi -Wall -pedantic" to stop complaining! */
extern int strcasecmp(const char*s1, const char *s2);
int fileno( FILE *stream);
#endif

#endif

#endif /*   __CONFIG_H */
