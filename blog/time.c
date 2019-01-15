#include"file.h"
int main(){
  int fd;
  char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  char *save[]={0};
  time_t t=time(NULL);//获取当前时间
  printf("当前时间为：%ld\n",t);
  struct tm *tt=gmtime(&t);//转换成格林尼治时间
  printf("gmtime:");
  printf("%d-%d-%d",(tt->tm_year+1900),(tt->tm_mon+1),(tt->tm_mday));
  printf("%s %d:%d:%d\n\n",wday[tt->tm_wday],tt->tm_hour,tt->tm_min,tt->tm_sec);
  tt=localtime(&t);//转换成当地时间
  printf("localtime:");
  printf("%d-%d-%d",(tt->tm_year+1900),(tt->tm_mon+1),(tt->tm_mday));
  printf("%s %d:%d:%d\n\n",wday[tt->tm_wday],tt->tm_hour,tt->tm_min,tt->tm_sec);
  time_t ttt=mktime(tt);//将当前时间转换回time_t类型
  printf("mktime:\n");
  printf("time_t=%ld\n",ttt);
  if((fd=open("txt","w"))<0){
	   printf("open file error!\n");
	   exit(1);
      }
  else {
    write(fd,tt->tm_year+1900,);

  }
   close(fd);
  return 0;
}

