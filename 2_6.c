#include"ch02.h"
#include"y_or_n_ques.c"
int main(int argc,char *argv[]){
 FILE *fd;
 fpos_t pos;
 if(!y_or_n_ques("Should we use append mode?"))
  {
    if((fd=fopen("test_file","w+"))==NULL)
		err_exit("open failed.....");
  }
 else{
  if((fd=fopen("test_file","a+"))==NULL)
	  err_exit("open failed...");
 }
fputs("123456789abcdefg",fd);
fseek(fd,0,SEEK_END);
fgetpos(fd,&pos);
printf("Now we stand in %ld\n",pos);
fseek(fd,30,SEEK_END);
fgetpos(fd,&pos);
printf("Now we call fseek(fd,30,SEEK_END);" "and stand in %ld\n",pos);
fputs("zengwei",fd);
fprintf(stdout,"Now we write 7 bytes(%s) to test_file\n","zengwei");
fgetpos(fd,&pos);
printf("Now we stand in %ld\n",pos);
fclose(fd);

exit(0);
}
