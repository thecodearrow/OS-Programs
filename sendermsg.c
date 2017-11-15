/*sender.c*/


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

struct mymsg{
long mtype;
char  msgtxt[50];
}message,buffer;

void main(){
int qid=msgget(100,IPC_CREAT|0666);

strcpy(message.msgtxt,"Hello from Sender!");
message.mtype=1;
msgsnd(qid,&message,20,0);
msgrcv(qid,&buffer,20,2,0);
printf("%s",buffer.msgtxt);


}
