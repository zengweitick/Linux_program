#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>
int g_int=1;
int main(int argc, char *argv[])
{

    int local_int=1;
    int *malloc_int=(int *)malloc(sizeof(int));

    *malloc_int=1;
    pid_t pid ;
    if((pid=fork())<0)
    {
        //perror("fork failed! errno=%s\n",stderr(errno));
        printf("error!!!\n");  
      return 1;
    }
    else if(pid==0)
    {
        local_int=0;
        g_int=0;
        *malloc_int=0;
        fprintf(stderr,"child change local global malloc value to 0\n ");
        free(malloc_int);
        sleep(10);
        fprintf(stdout,"child exit!\n");
        exit(0);
     }
    fprintf(stdout,"wait child exit!\n");
    waitpid(pid,NULL,0);
    fprintf(stdout," child have exit!\n");
    printf("parent g_int =%d\n",g_int);
    printf("parent local_int =%d\n",local_int);
    printf("parent malloc_int =%d\n",*malloc_int);
    free(malloc_int);
    return 0;
}
