#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(void)
{
   int server_fd;
   struct sockaddr_in myaddr;
   myaddr.sin_family = AF_INET;
   myaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //把字符格式的IP地址转换成32位格式的IP地址
   myaddr.sin_port = htons(8081);
   char buf[100];

   //1. socket
   server_fd = socket(AF_INET, SOCK_STREAM, 0);

   //2. connect
   if(connect(server_fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1) {
       perror("connect error");
       exit(1);
   }

   read(server_fd, buf, 100);
   printf("get message : %s", buf);
   close(server_fd);

    return 0;
}

