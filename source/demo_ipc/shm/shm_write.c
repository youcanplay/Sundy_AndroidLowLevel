#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main()
{
    void *shared_memory = (void *)0;
    char *contents = "hello reader.\n";
    //1. create shared memory.
    int shmid = shmget(34567, 2048, IPC_CREAT|0666);

    if(shmid != -1) {
        //2. map address.
        shared_memory = shmat(shmid, NULL, 0);
        if(shared_memory != (void *)-1) {
            //3. copy data to shared memory.
            memcpy(shared_memory, contents, strlen(contents));
            printf("save successful.\n");
            shmdt(shared_memory);
        } else {
            perror("shmat error");
        }

    } else {
        perror("shmget error");
    }

    return 0;
}
