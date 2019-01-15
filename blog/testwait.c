#include"file.h"
int main(){
   pid_t pid;
   int n=3;
   int result;
   int status;
   while(n--){
     pid=fork();
	 if(pid==0)break;
	 else if(pid<0){
      perror("fork\n");
     return 1;
	 }
   }
   if(pid==0){
	   sleep(1);
     printf("Hello I am child[%d]\n",getpid());
	 return n;
   }
   while(1){
   result=waitpid(-1,&status,WUNTRACED | WCONTINUED);
   printf("the result is :%d\n",result);
   if(result==-1){
   return 1;

   }
   }
  return 0;
}
