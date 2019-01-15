#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv){
    extern char **environ;
	char **env=environ;
	int i;
	for(i=0;i<argc;i++)
		printf("argv[%d]:%s\n",i,argv[1]);
	while(*env){
     printf("%s\n",*env);
	 env++;
	}
	exit(EXIT_SUCCESS);



}
