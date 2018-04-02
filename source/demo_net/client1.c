#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>

int main(void)
{
   int server_fd;
   struct sockaddr_un myaddr;
   myaddr.sun_family = AF_UNIX;
   strcpy(myaddr.sun_path, "sundysocketfile");
   char buf[100];

   //1. socket
   server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

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

