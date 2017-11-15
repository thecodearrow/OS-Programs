/*receiver.c*/


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

struct mymsg{
long mtype;
char  msgtxt[20];
}message,buffer;

void main(){
int qid=msgget(100,IPC_CREAT|0666);


msgrcv(qid,&buffer,20,1,0);
printf("%s",buffer.msgtxt);
strcpy(message.msgtxt,"Message received by receiver");
message.mtype=2;
msgsnd(qid,&message,20,0);



}
