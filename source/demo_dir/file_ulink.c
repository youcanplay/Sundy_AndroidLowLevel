#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret = unlink("hello");
    if(ret == 0) {
        printf("unlink success\n");
    }
    return 0;
}


