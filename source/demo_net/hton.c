#include <stdio.h>
#include <arpa/inet.h>
/*
* 网络字节序到主机字节序的转化函数
*/

int main()
{

    int l_ipcount = 0x01020304;
    int l_ipnet = htonl(l_ipcount);
    printf("(long)old is : %#x\n", l_ipcount);
    printf("(long)new is : %#x\n", l_ipnet);
    
    unsigned short s_ipcount = 0x0A0B;
    unsigned short s_ipnet = htons(s_ipcount);	
    printf("(short)old is : %#x\n", s_ipcount);
    printf("(short)new is : %#x\n", s_ipnet);
 
    return 0;
}


