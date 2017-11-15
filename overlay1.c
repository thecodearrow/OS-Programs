/*To demonstrate execl() system call*/ 

#include<stdio.h>
#include<unistd.h>

void main(){

printf("Overlay1 Program %d\n",getpid());
execl("/home/prashanth/overlay2","overlay2.out",NULL);
printf("THIS LINE WON'T BE PRINTED!");
}
