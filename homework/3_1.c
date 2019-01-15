#include"ch03.h"
#define MAXSIZE 40960
int main(int argc, char**argv){
 int n,from,to;
 clock_t start_t, end_t;
 double total_t;
 char buf[MAXSIZE];
 start_t=clock();
 printf("程序启动，时间为：start=%ld\n",start_t);
 if(argc!=3){
   printf("Usage : %s from-file to-file\n",argv[0]);
   exit(0);
 }
 if((from=open(argv[1],O_RDONLY))<0)
	 err_exit(argv[1]);
 if((to=open(argv[2],O_WRONLY | O_CREAT | O_APPEND,0644))<0)
	 err_exit(argv[2]);
 while((n=read(from,buf,sizeof(buf)))>0)
	 write(to,buf,n);
 close(from);
 close(to);
 end_t = clock();
printf("程序结束, 时间为：end= %ld\n", end_t);   
total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("当缓存区为 %d时,CPU 占用的总时间：%f\n",MAXSIZE,total_t);
printf("程序退出...\n");

}

