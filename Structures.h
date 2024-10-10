struct Connection
{
  int id_client;
  char name[50];
}; // 52 Bytes

struct Data
{
  int id_client;
  char name[50];
  int value;
}; // 268 Bytes

struct packet
{
  int type; // 1 --> Conn and 2 --> Data
  union
  {
    struct Connection conn;
    struct Data data;
  };
}; // 262
