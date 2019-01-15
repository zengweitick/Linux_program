#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fb,*fa;
fpos_t pos;
int offset=0;
char s;
char k;
printf("\n");
if((fb=fopen("sourcefile","r"))==NULL){
 printf("open file failed!!");
 exit(1);
}
fseek(fb,offset,SEEK_SET);
s=fgetc(fb);
printf("Please input the k(k<%c):",s+1);
k=tolower(fgetc(stdin));
if(k>s){
printf("overview!!!\n");

exit(0);
}
while(1){
  offset++;
  fseek(fb,offset,SEEK_SET);  
  s=fgetc(fb);
  if(s=='\n'){
  offset++;
  fseek(fb,offset,SEEK_SET);  
  s=fgetc(fb);
  if(s==k)break;
  else continue;
  }
}
while(s!='\n')
{ 
  offset++;
  fseek(fb,offset,SEEK_SET);  
  s=fgetc(fb);
  putchar(s);
}
printf("\n");
fclose(fb);
}
