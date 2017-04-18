#include <stdio.h>

#include <unistd.h>

#include<sys/types.h>

#include <stdlib.h>

#include <string.h>

void main()

{

int fd[2],bt;

pid_t child;

char tm[]="Dhiral";

char rb[20];

pipe(fd);

if ((child = fork()) == -1)

{

perror("fork");

}

if(child==0)

{

close(fd[0]);

write(fd[1],tm,(strlen(tm)+1));

exit(0);

}

else

{

close(fd[1]);

bt=read(fd[0],rb,sizeof(rb));

printf("\n write = %s\n",rb);

}

return;

}
