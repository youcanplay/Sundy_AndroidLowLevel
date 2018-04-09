/*
 *  创建多个线程，给线程传入参数。
 * */

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg);
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int main()
{
    pthread_t mypthread[3];
    int i;

    printf("start.\n");
     for(i=0; i<3; i++)
     {
        if(pthread_create(&mypthread[i], NULL, thread_function, (void *)i) != 0) 
        {
           printf("create thread failed.\n");
        }
     }
    while(1);

    return 0;
}

void *thread_function(void *arg)
{
    int i;

    pthread_mutex_lock(&mymutex);	
    for(i=0; i<5; i++) {
        printf("thread num = %d.\n", (int)arg);
    }

    pthread_mutex_unlock(&mymutex);
	
    pthread_exit(NULL);	
}

