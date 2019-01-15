#include"ch02.h"
#define BUF_SIZE 8
int main(void){
 FILE * fp;
 int fgets_yes;
 struct iobuf{
    char buf[BUF_SIZE];
	char other[BUF_SIZE];
 }buffer;
 memset(&buffer,'\0',sizeof(struct iobuf));
 do{
	 fgets_yes=y_or_n_ques("Should we read line by fgets()?");
	 fprintf(stdout,"Enter a line\n");
	 if(fgets_yes){
       fgets(buffer.buf,BUF_SIZE,stdin);
	   fprintf(stdout,"fgets()1 get the string:\"%s\"\n",buffer.buf);
	   fprintf(stdout,"fgets()'s size is %ld\n",strlen(buffer.buf));
	   //  if(buffer.buf[strlen(buffer.buf)-1]!='\n')
	   // {
       //  fgets(buffer.buf,BUF_SIZE,stdin);
	   //  fprintf(stdout,"fgets()2 get the string:\"%s\"\n",buffer.buf);
	   // }

	 }else{
       gets(buffer.buf);
	   fprintf(stdout,"gets() get the string  :\"%s\"\n",buffer.buf);
	   printf("the gets's size is %ld\n",strlen(buffer.buf));
	 }
      fprintf(stdout,"other is string:\"%s\"\n",buffer.other);

 }while(y_or_n_ques("continue ?"));
 exit(0);


}
