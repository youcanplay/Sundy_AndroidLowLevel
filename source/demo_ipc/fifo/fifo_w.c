#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_PATH   "myfifofile"

//write fifo
int main(void)
{
    int ret = -1;
    int fifo_fd = -1;
    char *conten_w = "hello fifo reader.\n";

    //create fifo
    ret = mkfifo(FIFO_PATH, 0666);
    if(ret < 0 && errno != EEXIST) {    //create faild and fifo file no exist
        perror("create fifo failed");
        exit(EXIT_FAILURE);
    } else {
        printf("create fifo sucess.\n");
        //open fifo file
        fifo_fd = open(FIFO_PATH, O_WRONLY|O_CREAT, 0666);
        if(fifo_fd > 0) {
            //write fifo
            while(1)
            {
                ret = write(fifo_fd, conten_w, strlen(conten_w));
                if(ret > 0) {
                    printf("write fifo sucess.\n");
                }
                sleep(2);
            }
        }
    }

    close(fifo_fd);

    return 0;
}


