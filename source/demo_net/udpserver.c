#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int server_fd;
    char buf[100];
    struct hostent *myhost;
    struct sockaddr_in myaddr;
    struct sockaddr_in clientaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(8081);
    int addr_len = sizeof(myaddr);
    //1.socket
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(server_fd == -1) {
	perror("sock error");
	exit(1);
    }

    //2.bind
    if(bind(server_fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1) {
        perror("bind error");
	exit(1);
    }

    //3.op
    recvfrom(server_fd, buf, 100, 0, (struct sockaddr *)&clientaddr, &addr_len);
    printf("get from client:%s\n", buf);
   
    //3.close
    close(server_fd);

    return 0;	

}



