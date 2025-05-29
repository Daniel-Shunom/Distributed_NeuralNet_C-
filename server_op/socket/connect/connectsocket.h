#include <stdio.h>
#include "../socket/socket.h"
#pragma once

namespace http {
  class connectsocket: dnnsocket {
  private:
  public: 
    connectsocket(int domain, int service, int protocol, int port, u_long bridge);
    int connect_to_network(int sock, struct sockaddr_in address);
  };
}