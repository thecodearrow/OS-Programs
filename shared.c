#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>

int main(){

int pid;
int shmid=shmget(1,20,IPC_CREAT|0666);
int *ptr=shmat(shmid,0,0);
pid=fork();
if(pid<0){

printf("Fork Error");

}

if(pid>0){

*ptr="Message from parent";

}

if(pid==0){

printf("Child! %s",*ptr);
}
}
