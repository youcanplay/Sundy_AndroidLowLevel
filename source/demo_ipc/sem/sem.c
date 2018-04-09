#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

key_t semid;

struct sembuf sem_down = {0, -1, 0};
struct sembuf sem_up = {0, 1, 0};
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};


void down()
{
    semop(semid, &sem_down, 1);	
}

void up()
{
    semop(semid, &sem_up, 1);
}

int main()
{
    int ret = -1;
    union semun arg;
    arg.val = 1;
    semid = semget((key_t)22345, 1, IPC_CREAT|0666);
    if(semid == -1) {
	perror("semget error");
	return 1;
    }	   
 
    ret = semctl(semid, 1, SETVAL, arg);
    if(ret == -1) {
	perror("semctl error");
	return 1;     
    }


    if(semid != -1) {
	down();
	printf("hello world.\n");
	sleep(10);
	up();
     }

    return 0;
}



