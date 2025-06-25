#pragma once

#include <iostream>
#include <cstdint>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif

namespace http {
class dnnsocket {
private:
  struct sockaddr_in address; 
  int sock;
  int connection;
public:
  dnnsocket(int domain, int service, int protocol, uint16_t port, uint32_t bridge);
  ~dnnsocket();
  virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
  void test_connection(int con);
  struct sockaddr_in get_address();
  int get_socket();
  int get_connection();
  void set_connection(int con);
};
}
