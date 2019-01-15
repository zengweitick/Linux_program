#include"ch03.h"
#define bufsize  1024
int main(int argc,char *argv[]){
   int from,to;
   int n=0;
   char buf[bufsize];
   if(argc!=3){
      printf("Usage :%s from-file to-file\n",argv[0]);
	  exit(1);
   }
   if((from=open(argv[1],O_RDONLY))<0)err_exit(argv[1]);
   if((to=open(argv[2],O_WRONLY|O_CREAT|O_APPEND,0644))<0)err_exit(argv[2]);   while((n=read(from,buf,sizeof(buf)))>0)
      write(to,buf,n);
	  close(from);
	  close(to);
}
