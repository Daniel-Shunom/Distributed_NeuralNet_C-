#include <stdio.h>
#include "../socket/socket.h"
#pragma once

namespace http {
  class connectsocket: dnnsocket {
  private:
  public: 
    connectsocket(int domain, int service, int protocol, uint16_t port, uint32_t bridge);
    int connect_to_network(int sock, struct sockaddr_in address);
  };
}