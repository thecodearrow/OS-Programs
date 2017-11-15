
/*To demonstrate multiple pipes IPC*/

#include<stdio.h>
#include<unistd.h>

void main(){

int fds1[2],fds2[2],pid;
char message1[15],message2[15];
pipe(fds1);
pipe(fds2);
pid=fork();

if(pid>0){
fflush(stdin);
printf("Parent process! \n");
write(fds1[1],"HiPrashanth!\n",15);
sleep(3);
read(fds2[0],message1,15);
write(1,message1,15);
printf("\n");



}

if(pid==0){
fflush(stdin);
printf("Child process! \n");
sleep(3);
read(fds1[0],message2,15);
write(1,message2,15);
write(fds2[1],"Hi Vaidyaaaa!\n",15);


}


}
