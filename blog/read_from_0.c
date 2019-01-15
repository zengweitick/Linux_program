#include"file.h"
#define size 10
int main(){
  off_t pos;
  FILE *stream;
  int n;
  char buf[size];
 n=fread(buf,sizeof(buf),1,stdin);
  printf("%s",buf);
  stream=fopen("./txt","w+");
  fwrite(buf,sizeof(buf),1,stream);
  fclose(stream);  
  
}
