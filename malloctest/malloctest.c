#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
 char *s=NULL;
 s=(char *)malloc(sizeof(char *)*15);
 if(s==NULL){
   printf("error!!!\n");
   exit(EXIT_SUCCESS);

 }
sprintf(s,"%s","Helloworlf\n");
 //s="hello world";
 printf("string : s=%s\n",s);
 free(s);

}
