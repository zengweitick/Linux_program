#include"signal.h"
int main(int argc ,char **argv){
if(argc!=2){
   printf("error!\n");
   exit(1);

}
pid_t pid=atoi(argv[1]);
union sigval val;
while(1){
   scanf("%d",&val.sival_int);
   if(sigqueue(pid,SIGQUIT,val)<0){
   
      perror("sigqueue");  
   }
}


}
