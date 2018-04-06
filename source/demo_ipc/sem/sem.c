#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

key_t semid;

struct sembuf sem_down = {0, -1, 0};
struct sembuf sem_up = {0, 1, 0};

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
    semid = semget(12345, 1, IPC_CREAT|0666);
   // union semun arg;
  //  ushort array[100] = {0};
//    arg.array = array;
    //arg.val = 1;
    if(semctl(semid, 1, SETVAL) == -1) {
	perror("semctl error");
    }
    if(semid != -1) {
	down();
	printf("hello world.\n");
	sleep(10);
	up();
     }

    return 0;
}



