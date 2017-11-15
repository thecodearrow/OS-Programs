#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

struct mymsg{
long mtype;
char msgtxt[50];

}message_send1,message_send2,message_receive1,message_receive2;
int main(){
int pid,qid;
int send,receive; //To check the status of the system calls
qid = msgget( (key_t)100, IPC_CREAT|0666);
if(qid<0){
printf("Failed to create message queue");
}
pid=fork(); //Creates a new process
if(pid<0){
printf("Fork Error");
}
if(pid>0){
//Parent Process

strcpy(message_send1.msgtxt,"Hello from Parent Message1!\n");
message_send1.mtype=1;
send=msgsnd(qid,&message_send1,50,0);
strcpy(message_send2.msgtxt,"Hello from Parent Message 2!\n");
message_send2.mtype=2;
send=msgsnd(qid,&message_send2,50,0);

}

if(pid==0){
//Child Process
receive=msgrcv(qid,&message_receive1,50,1,0); 
printf("%s",message_receive1.msgtxt);
receive=msgrcv(qid,&message_receive2,50,2,0); 
printf("%s",message_receive2.msgtxt);


}




return 0;
}
