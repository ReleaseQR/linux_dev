/*************************************************************************
	> File Name: server.c
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月01日 星期日 12时05分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERV_PORT               8080
#define MAXLEN                  100

int main(int argc, char **argv)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    int n = 0;
    char buf[100] = {0};
    char *sendbuf = "I got your data";
    char str[INET_ADDRSTRLEN];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 20);

    printf("Server is Open, wait for connections......\n");
    while(1)
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);

        n = read(connfd, buf, MAXLEN);
        printf("Received from %s at Port %d \n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
              ntohs(cliaddr.sin_port));

        write(connfd, sendbuf, strlen(sendbuf));
        close(connfd);
        
    }
    return 0;
}
