#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    char buf[1024];
    ssize_t ret;
    //int file_len;
    char w_buf[1024] = "nice to meet you!\r\n";

    fd = open("file.in", O_RDWR|O_CREAT, 0666);
    if(fd < 0) {
        printf("open file.in failed!\n");
        exit(1);
    }

    ret = read(fd, buf, 1024);
    if(ret > 0) {
        printf("%s", buf);
    } else {
        printf("read file failed!\n");
    }

    //file_len = strlen(buf);
    lseek(fd, 0, SEEK_END);
    ret = write(fd, w_buf, strlen(w_buf));
    if(ret < 0) {
        printf("write file fialed!\n");
    }

    lseek(fd, 0, SEEK_SET);
    ret = read(fd, buf, 1024);
    if(ret > 0) {
        printf("%s", buf);
    } else {
        printf("read file failed!\n");
    }

    close(fd);
    return 0;
}

