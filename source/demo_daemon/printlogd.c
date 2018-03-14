#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    pid_t pid;
    unsigned int i;
    int fd;
    char *count = "hello menkong log\n";
    int ret;
    //1. 创建新的进程.
    pid = fork();
    if(pid < 0) {
        perror("fork");
    } else if(pid > 0){
        exit(0);
    }
    //2. 设置新的回话
    setsid();
    //3.关闭所有文件描述符.
    for(i=0; i<101122; i++) {
        close(i);
    }
    //4. 改变工作目录。
    chdir("/");
    //5. 修改文件掩码。
    umask(0);
    //6. 处理事件。
    while(1)
    {
        fd = open("/tmp/mylog.log", O_CREAT|O_RDWR|O_APPEND, 0666);
        if(fd < 0) {
            perror("open");
            exit(1);
        }
        ret = write(fd, count, strlen(count));
        if(ret < 0) {
            perror("write");
        }
        sleep(5);
    }
    return 0;
}
