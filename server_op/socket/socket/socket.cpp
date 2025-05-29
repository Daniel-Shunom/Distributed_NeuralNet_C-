#include "./socket.h"

http::dnnsocket::dnnsocket(int domain, int service, int protocol, int port, u_long bridge) {
  // NOTE -> we have defined the address structure;
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(bridge);
  // NOTE -> we have defined the socket;
  sock = socket(domain, service, protocol);
  test_connection(sock);
  // NOTE -> we have establish our connection;
  connection = connect_to_network(sock, address);
  test_connection(connection);
}

void http::dnnsocket::test_connection(int con) {
  // NOTE -> if the connection fails, we will exit the program;
  // this is a simple test to ensure that the connection was established;
  if (con < 0) {
    perror("Failed to connect ....");
    exit(EXIT_FAILURE);
  }
}

// NOTE -> we have defined the getters for the address, connection, and socket;

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