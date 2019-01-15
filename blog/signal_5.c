#include"file.h"
void waitchild(int signal){
  int status;
  pid_t pid;
  while((pid=waitpid(-1,&status,WUNTRACED | WCONTINUED))>0){
	  if(WIFEXITED(status)){
            printf("Child[%d] exited! return code=%d\n\n",getpid(),WEXITSTATUS(status));
	  }
	  else if(WIFSIGNALED(status)){
         printf("Child[%d] terminated by signal %d\n\n",getpid(),WTERMSIG(status));
	  }
	 else if(WIFSTOPPED(status)){
             printf("Child[%d] stopped by signal:%d\n\n",getpid(),WSTOPSIG(status));
	  }
 	  else if(WIFCONTINUED(status)){
                printf("Child[%d] continued \n\n",getpid());
  
	  }

  }
}
void child(int n){
   if(n==9) *((int *)0)=0;
   exit(n+1);
}
int main(){
    printf("I am %d\n",getpid());
    if(SIG_ERR==signal(SIGCHLD,waitchild)){
      perror("signal SIGSTOP");
    }
    int n=10;
    pid_t pid;
    while(n--){
    pid=fork();
    if(pid==0){
     child(n);
    }
    else if(pid==-1){
       perror("fork");
    }
    }
    return 0;

}
