#include"socket.h"
int main(){
	int sockfd,ret,n;
	char buf[64];
	struct sockaddr_in servaddr,cliaddr;
	socklen_t cliaddrlen;
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(8080);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	ret=connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	cliaddrlen=sizeof(cliaddr);
	ret=getsockname(sockfd,(struct sockaddr*)&cliaddr,&cliaddrlen);
	printf("cliaddr:%s:%d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	n=read(sockfd,buf,64);
	write(STDOUT_FILENO,buf,n);
	close(sockfd);
	return 0;
}
