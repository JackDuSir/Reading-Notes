/*************************************************************************
	> File Name: epoll_server.h
	> Author: Mr.Miaow
	> Mail: miaopei163@163.com 
	> Created Time: 日  4/14 15:53:02 2019
 ************************************************************************/
#ifndef _EPOLL_SERVER_H
#define _EPOLL_SERVER_H

int init_listen_fd(int port, int epfd);
void epoll_run(int port);

#endif

