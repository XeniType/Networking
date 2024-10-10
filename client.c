#include <stdio.h>
#include <winsock2.h>
#include "Structures.h"
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char **argv)
{

  WSADATA wsa;
  SOCKET sock;
  int bytes;
  struct sockaddr_in ip;
  int ip_size = sizeof(ip);
  struct packet pkt;
  char res[2];

  WSAStartup(MAKEWORD(2, 0 ), &wsa);
  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  ip.sin_family = AF_INET;
  ip.sin_addr.s_addr = inet_addr("127.0.0.1");
  ip.sin_port = htons(9999);

  connect(sock, (SOCKADDR *)&ip, sizeof(ip));

  while (1)
  {

    memset(&pkt, 0, sizeof(pkt));
    printf("\nPacket of Connection(c) or Data(d)");
    fgets(res, sizeof(res), stdin);
    if (strncmp(res, "c",1) == 0)
    {

      pkt.type = 1;
      pkt.conn.id_client = 0;
      getchar();
      printf("\nName: ");
      fgets(pkt.conn.name, sizeof(pkt.conn.name), stdin);
    }
    else if (strncmp(res, "d",1) == 0)
    {

      pkt.type = 2;
      pkt.data.id_client = 0;
      getchar();
      printf("\nName: ");
      fgets(pkt.data.name, sizeof(pkt.data.name), stdin);
      printf("\nGive Value: ");
      scanf("%d", &pkt.data.value);
    }

    send(sock, (char *)&pkt, sizeof(ip),0);

  }

  return 0;
}