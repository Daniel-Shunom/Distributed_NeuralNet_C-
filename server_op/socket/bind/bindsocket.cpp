#include "./bindsocket.h"

http::bindsocket::bindsocket(int domain, int service, int protocol, uint16_t port, uint32_t bridge)
: dnnsocket(domain, service, protocol, port, bridge) {
  set_connection(connect_to_network(get_socket(), get_address()));
  test_connection(get_connection());
}

int http::bindsocket::connect_to_network(int sock, struct sockaddr_in address) {
  return bind(sock, (struct sockaddr *)(&address), sizeof(address));
}