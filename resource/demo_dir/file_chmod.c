#include <sys/stat.h>
#include <stdio.h>

int main()
{
    umask(0000);
    int ret = chmod("hello", 0666);
    if(ret == 0) {
        printf("chmod success\n");
    }
    return 0;
}


