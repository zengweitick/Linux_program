#include"socket.h"
int main(){
      struct sockaddr_in servaddr,cliaddr;
	  int sockfd,clentfd,ret;
	  socklen_t cliaddrlen;
	  servaddr.sin_family=AF_INET;
	  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	  servaddr.sin_port=htons(8080);
	  sockfd=socket(AF_INET,SOCK_STREAM,0);
	  ret=bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	  ret=listen(sockfd,10);
	  cliaddrlen=sizeof(cliaddr);
	  clentfd=accept(sockfd,(struct sockaddr *)&cliaddr,&cliaddrlen);
	  printf("client fd:%d\n",clentfd);
	  printf("sockaddr:%s:%d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	  cliaddrlen=sizeof(cliaddr);
	  ret=getsockname(clentfd,(struct sockaddr*)&cliaddr,&cliaddrlen);
	  printf("sockaddr:%s:%d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	  write(clentfd,"Hello Linux");
	  close(clentfd);
	  close(sockfd);
	  return 0;
}
