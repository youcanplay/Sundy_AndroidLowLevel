#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	//fork创建的进程会从头开始执行一遍
	pid_t pid;
	pid = fork();
	int counter = 0;
	counter ++;
	if(pid < 0) {
		printf("create process failed!\n");
		exit(1);
	} else if(pid == 0) {
		printf("child counter:%d.\n", counter);
	} else if(pid > 0) {
		printf("parent counter:%d.\n", counter);
	}
	return 0;
}

