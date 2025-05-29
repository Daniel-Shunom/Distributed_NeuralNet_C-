#include "./socket.h"

http::dnnsocket::dnnsocket(int domain, int service, int protocol, uint16_t port, uint32_t bridge) {
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(bridge);
  sock = socket(domain, service, protocol);
  test_connection(sock);
  connection = connect_to_network(sock, address);
  test_connection(connection);
}

void http::dnnsocket::test_connection(int con) {
  if (con < 0) {
    std::cerr << "Failed to connect ...";
    std::exit(EXIT_FAILURE);
  }
}

struct sockaddr_in http::dnnsocket::get_address() {
  return address;
}

void http::dnnsocket::set_connection(int con) {
  connection = con;
}

int http::dnnsocket::get_connection() {
  return connection;
}

int http::dnnsocket::get_socket() {
  return sock;
}