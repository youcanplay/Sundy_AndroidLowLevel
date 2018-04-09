#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

//通过主机名获取ip地址
int main(int argc, char *argv[])
{
    if(argc < 2) {
        perror("argment count error");
        exit(1);
    }
    
   int server_fd;
   struct sockaddr_in myaddr;
   struct hostent *myhost;
   myaddr.sin_family = AF_INET;
   myhost = gethostbyname(argv[1]);
   if(!myhost) {
       perror("gethost error");
       exit(1);
   }
   char buf[100];

   myaddr.sin_addr = *((struct in_addr *)myhost->h_addr); //把字符格式的IP地址转换成32位格式的IP地址
   myaddr.sin_port = htons(8081);

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

