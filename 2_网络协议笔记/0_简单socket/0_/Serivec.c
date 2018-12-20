/*************************************************************************
	> File Name: Serivec.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月22日 星期四 20时37分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAXLINE     80
#define SERV_PORT   8000

int main(int argc, char** argv)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;

    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];

    int n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0); //TCP采用的为流式套接字

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    listen(listenfd, 20);
    printf("Accepting connections...\n");

    while(1)
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);

        n = read(connfd, buf, MAXLINE);
        for (int i = 0; i < n; i++)
            printf("%c, ", buf[i]);
        printf("\n");

        close(connfd);

        usleep(10);
    }
    return 0;
}
