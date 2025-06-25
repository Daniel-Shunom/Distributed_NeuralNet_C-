#include <stdio.h>
#include "../socket/socket.h"
#pragma once

namespace http {
class bindsocket: dnnsocket {
private:
public: 
  bindsocket(int domain, int service, int protocol, uint16_t port, uint32_t bridge)
  : dnnsocket(domain, service, protocol, port, bridge){};

  int connect_to_network(int sock, struct sockaddr_in address);
};
}
