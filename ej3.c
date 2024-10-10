#include "stdio.h"
#include "WinSock2.h"
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char** argv)
{

  WSADATA wsa;
  SOCKET sock;
  struct sockaddr_in ip;
  char buffer[256];
  int ipsize;

  WSAStartup(MAKEWORD(2,0), &wsa);

  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr=inet_addr("127.0.0.1");
  ip.sin_port = htons(7979);

  connect(sock,(SOCKADDR*)&ip, sizeof(ip));
  while(1)
  {
    memset(buffer,0,sizeof(buffer));
    printf("Cadena: ");
    fgets(buffer,sizeof(buffer), stdin);
    send(sock,buffer,sizeof(buffer),0);

  }

  return 0;

}
