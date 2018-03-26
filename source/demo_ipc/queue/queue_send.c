#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    mybuf.mtype  = 1;
    strcpy(mybuf.mtext, "hello message receiver.");
    msgid = msgget(1234, IPC_CREAT | 0666);
    if(msgid != -1) {
        printf("get message queue success.\n");
        if(msgsnd(msgid, (void *)&mybuf, sizeof(mybuf.mtext), 0) != -1) {
            printf("send successfully message to %d .\n", msgid);
        } else {
            printf("send message");
        }
    
    } else {
        perror("get message");
    }
    return 0;
}

