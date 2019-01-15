#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int fd; 
    if((fd = open(argv[1],O_RDWR))<0){
        printf("open file failed\n");
        exit(1);
    }   
    int i = 0;
    int status;
    char c;
    int pid;
    if((pid=fork()) < 0){ 
        printf("fork failed\n");
        exit(1);
    } else if (pid == 0){ 
        while(read(fd, &c, 1)>0){
			printf("\nchild process\n");
            write(STDOUT_FILENO, &c, 1); 
            sleep(1);
        }   
    }else{
        while(read(fd, &c, 1)>0){
						printf("\nfather process\n");
            write(STDOUT_FILENO, &c, 1); 
            sleep(1);
        }   
        if(wait(&status) != pid){
            printf("wait error\n");
        }   
    }   
    return 0;
}
