#include <stdio.h>
#include <winsock2.h>
#include "Structures.h"
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char **argv)
{

  WSADATA wsa;
  SOCKET sock_c,sock;
  int bytes, clients = 0;
  struct sockaddr_in ip, ipc;
  int ip_size=sizeof(ip);
  struct packet pkt;

  WSAStartup(MAKEWORD(2,0),&wsa);
  sock=socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
  ip.sin_family=AF_INET;
  ip.sin_addr.s_addr=inet_addr("0.0.0.0");
  ip.sin_port = htons(9999);

  bind(sock,(SOCKADDR*)&ip, sizeof(ip));

  listen(sock,SOMAXCONN);
  sock_c = accept(sock,(SOCKADDR*)&ipc,&ip_size);
  printf("Client succesfully connected = [%s:%d]",
          inet_ntoa(ipc.sin_addr),ntohs(ipc.sin_port));
  while (1)
  {
    bytes = recv(sock_c,(char *) &pkt, sizeof(pkt), 0);
    if(bytes > 0)
    {

      if(pkt.type == 1)//packet Connection
      {
        clients++;
        printf("\nNew Client [%d]",clients);
        printf("\nClient [%s]",pkt.conn.name);

      } 
      else if(pkt.type == 2)//packet Data
      {

        printf("\nNew Data:\n");
        printf("\nID Client: [%d] \nString: [%s] \nValue: [%d]",
                pkt.data.id_client, pkt.data.name, pkt.data.value);

      }

    }
  }
  

  return 0;

}
