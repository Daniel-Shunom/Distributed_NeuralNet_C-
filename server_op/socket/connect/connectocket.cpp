#include "./connectsocket.h"

http::connectsocket::connectsocket(int domain, int service, int protocol, int port, u_long bridge) 
: dnnsocket(domain, service, protocol, port, bridge) {
  set_connection(connect_to_network(get_socket(), get_address()));
  test_connection(get_connection());
}

int http::connectsocket::connect_to_network(int sock, struct sockaddr_in address) {
  return connect(sock, (struct sockaddr *)(&address), sizeof(address));
}