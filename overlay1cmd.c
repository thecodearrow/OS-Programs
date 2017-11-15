/*To demonstrate execl() system call* using cmdline args*/ 

#include<stdio.h>
#include<unistd.h>

printf("Overlay1 Program %d\n",getpid());
execl(argv[1],argv[2],NULL);
printf("THIS LINE WON'T BE PRINTED!");
}
