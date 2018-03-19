#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int pfd[2];
    int ret;
    pid_t pid;
    char *w_cont = "hello pipe reader\n";
    char r_cont[256];

    ret = pipe(pfd);
    if(ret < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    } else {
        pid = fork();
        if(pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if(pid > 0) {
            // parent process
            close(pfd[0]);
            write(pfd[1], w_cont, strlen(w_cont));
            wait(0); // wait child process finish.
        } else {
            // childe process
            sleep(3);
            close(pfd[1]);
            read(pfd[0], r_cont, 255);
            printf("read form pipe: %s",r_cont);
        }
    }
    return 0;
}

