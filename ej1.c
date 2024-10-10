#include <stdio.h>
#include "WinSock2.h"

int main(int argc, char **argv)
{

  WSADATA wsa;
  //SOCKET sock_listen, sock_clients[10];
  SOCKET sock_UDP, sock_TCP;
  WSAStartup(MAKEWORD(2,0),&wsa);

  struct sockaddr_in ip;

  sock_UDP = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP) ;//UDP INET:IPv4
  sock_TCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//TCP INET:IPv4


  ip.sin_family = AF_INET;
  ip.sin_port = htons(9999);
  ip.sin_addr.s_addr = inet_addr("0.0.0.0");
  bind(sock_TCP, (SOCKADDR*) &ip,sizeof(ip));
  listen(sock_TCP, 10);
  while (1);
  return 0;


  /* 
  @ Sockets:
  @   -TCP: (reliable - Conecction - Slow)
  @     -> number of clients + 1
  @     -> 4 Player game: 5 sockets
  @   -UDP: (LESS RELIABLE - Fast - Not oriented to connection)
  @     -> Only one socket
  
  */

}
