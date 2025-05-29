#include <stdio.h>
#include "../socket/socket.h"
#pragma once

namespace http {
  class bindsocket: dnnsocket {
  private:
  public: 
    bindsocket(int domain, int service, int protocol, int port, u_long bridge)
    : dnnsocket(domain, service, protocol, port, bridge){};

    int connect_to_network(int sock, struct sockaddr_in address);
  };
}
