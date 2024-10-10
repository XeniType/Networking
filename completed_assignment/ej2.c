#include "stdio.h"
#include "WinSock2.h"
#pragma comment(lib, "ws2_32.lib")


int main(int argc, char **argv)
{

  WSADATA wsa;
  SOCKET sock_listen, sock_clients[10];
  struct sockaddr_in ip, ip_temp;
  char buffer[256];
  int ipsize;
  WSAStartup(MAKEWORD(2,0), &wsa);
  sock_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("0.0.0.0");
  ip.sin_port = htons(7979);

  bind(sock_listen, (SOCKADDR*)&ip, sizeof(ip));

  listen(sock_listen,SOMAXCONN);  
  ipsize = sizeof(ip);
  sock_clients[0] = accept(sock_listen, (SOCKADDR*)&ip_temp, &ipsize);
  while(1)
  {

    memset(buffer,0,sizeof(buffer));
    recv(sock_clients[0],buffer,sizeof(buffer),0);
    printf("Recibido: %s",buffer);

  }
  return 0;

}