/*To create 2 child processes and make the parent process wait for the completion of both the child processes*/ 


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main(){

int pid1,pid2,i;

pid1=fork();
if(pid1>0){
i=wait(NULL); /*spits out child process id*/
printf("Parent Process ID: %d\n",getpid());
printf("%d\n",i);

}

if(pid1==0){
printf("Child Process 1 with ID %d and parent %d\n",getpid(),getppid());
printf("Forking another child.... \n");
pid2=fork();
if(pid2>0){
i=wait(NULL);
printf("%d\n",i);  /*spits out child process id*/
}

if(pid2==0){
printf("Child Process 2 with ID %d and parent %d\n",getpid(),getppid());
}
}



}
