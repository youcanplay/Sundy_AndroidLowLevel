#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_PATH   "myfifofile"

//read fifo
int main(void)
{
    int ret = -1;
    int fifo_fd = -1;
    char conten_r[256];

    //create fifo
    ret = mkfifo(FIFO_PATH, 0666);
    if(ret < 0 && errno != EEXIST) {    //create faild and fifo file no exist
        perror("create fifo failed");
        exit(EXIT_FAILURE);
    } else {
        printf("create fifo sucess.\n");
        //open fifo file
        fifo_fd = open(FIFO_PATH, O_RDONLY|O_CREAT, 0666);
        if(fifo_fd > 0) {
            //read fifo
            while(1)
            {
                ret = read(fifo_fd, conten_r, 256);
                printf("read:%s", conten_r);
            }
            close(fifo_fd);
        } else {
            perror("open fifo fiald");
        }
    }

    close(fifo_fd);

    return 0;
}


