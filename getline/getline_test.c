#include<stdio.h>
#include<stdlib.h>
int main(){
   FILE *stream;
   char *line=NULL;
   ssize_t len=0;
   ssize_t read;
   stream=fopen("file_1","r");
   if(stream==NULL){
      exit(EXIT_FAILURE);
   }
   while((read=getline(&line,&len,stream))!=-1){
       printf("Retrieve line of lenth %zu:\n",read);
	   printf("%s",line);
   }
   if(line){
    free(line);
   }
  exit(EXIT_SUCCESS);
}
