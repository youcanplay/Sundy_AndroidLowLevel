#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("create process failed!\n");
		exit(1);
	} else if(pid == 0) {
		printf("child process:%d.\n", getpid());
	} else if(pid > 0) {
		printf("parent process:%d.\n", getpid());
	}
	return 0;
}

