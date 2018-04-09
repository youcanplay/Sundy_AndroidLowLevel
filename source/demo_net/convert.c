#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/*
*  32位格式IP地址与字符串格式IP地址转化
*/

int main()
{

    struct in_addr my_addr;
    struct hostent *myhost;


    //convert a to net
    //inet_aton("192.168.0.1", &my_addr);
    //printf("a to net is:%#x\n", my_addr.s_addr);
    //printf("address is: %s\n", inet_ntoa(my_addr));

    //get host by name
    myhost = gethostbyname("www.qq.com");
    my_addr.s_addr = (uint32_t)(myhost->h_addr);
    printf("www.baidu.com ip is : %s \n", inet_ntoa(my_addr));

    return 0;	
}


