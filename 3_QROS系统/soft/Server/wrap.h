/*************************************************************************
	> File Name: wrap.h
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月01日 星期日 13时22分42秒
 ************************************************************************/

#ifndef _WRAP_H
#define _WRAP_H

void perr_exit(const char *s);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t Read(int fd, void *ptr, size_t nbytes);
ssize_t Write(int fd, const void *ptr, size_t nbytes);
void Close(int fd);
ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Write(int fd, const void *vptr, size_t n);
#endif
