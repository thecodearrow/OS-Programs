#include<stdio.h>
#include<unistd.h>

void main(){

int fds[2],pid;
char message[15];
pipe(fds);
pid=fork();

if(pid>0){
printf("Parent process! \n");
write(fds[1],"Hi  Prashanth!",15);



}

if(pid==0){
printf("Child process! \n");
read(fds[0],message,15);
write(1,message,15); //to stdout (monitor)

}


}
