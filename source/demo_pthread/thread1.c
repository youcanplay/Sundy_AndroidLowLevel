/*
 *  创建线程        --> pthread_create
 *  等待线程结束    --> pthread_join
 *  线程退出        --> pthread_exit
 * */

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    pthread_t mythread;
    char *message = "hello thread.\n";
    void *retval;

    if(pthread_create(&mythread, NULL, thread_function, (void *)message) != 0) {
        printf("create thread failed!\n");
    }
    
    // 等待线程结束返回
    pthread_join(mythread, &retval);
    printf("get result:%s",(char *) retval);

//    while(1);
    return 0;
}

void *thread_function(void *arg)
{
    printf("thread get message:%s", (char *)arg);
    // 线程返回的内容
    pthread_exit("good bye.\n");
}


