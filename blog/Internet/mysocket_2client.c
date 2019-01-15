#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define ERR_EXIT(msg) do { perror(msg); exit(1); } while(0)

int main() {
  int sockfd, ret;
  struct sockaddr_in servaddr;
  struct sockaddr_in cliaddr;
  socklen_t cliaddrlen;

  servaddr.sin_family = AF_INET;
  // 连接地址改成服务器监听的那个地址
  servaddr.sin_addr.s_addr = inet_addr("192.168.43.138");
  servaddr.sin_port = htons(8080);

  sockfd = socket(AF_INET, SOCK_STREAM, 0); 
  if (sockfd < 0) ERR_EXIT("socket");

  ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
  if (ret < 0) ERR_EXIT("connect");
  puts("connect successful");

  cliaddrlen = sizeof(cliaddr);
  ret = getsockname(sockfd, (struct sockaddr*)&cliaddr, &cliaddrlen);
  if (ret < 0) ERR_EXIT("getsockaddr");

  printf("cliaddr: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

  //while(1) pause();

  return 0;
}
 
