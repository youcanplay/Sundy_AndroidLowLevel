#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// 定义消息结构体
struct msgbuf
{
    long mtype; //消息类型
    char mtext[256];    //消息内容
};

int main()
{
    int msgid;
    int ret;
    struct msgbuf mybuf;

    //1. 创建消息
    msgid = msgget(1234, IPC_CREAT | 0666);
    if(msgid != -1) {
        printf("get message queue success.\n");
        //2. 接收消息
        if(msgrcv(msgid, (void *)&mybuf, sizeof(mybuf.mtext), 0, IPC_NOWAIT) != -1) {
            printf("receive successfully : %s\n ", mybuf.mtext);
        //3. 删除消息
            if(msgctl(msgid, IPC_RMID, 0) != -1) {
                perror("delete message");
            }
        } else {
            printf("receive message");
        }
    
    } else {
        perror("get message queue");
    }
    return 0;
}

