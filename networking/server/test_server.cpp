#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "test_server.hpp"

void AD::TestServer::acceptor()
{
  auto address = Server::getSocket()->get_address();
  auto socket = Server::getSocket()->get_socket();
  int addrlen = sizeof(address);

  new_socket = accept(socket, (struct sockaddr *)&address, (socklen_t *)&addrlen);

  read(new_socket, buffer, 30000);
}

void AD::TestServer::handler()
{
  std::cout << buffer << std::endl;
}

void AD::TestServer::responder()
{
  char *hello = "Hello from server";
  write(new_socket, hello, strlen(hello));
  close(new_socket);
}

AD::TestServer::TestServer(): AD::Server
(
  AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10
)
{
  launch();
}

void AD::TestServer::launch()
{
  while(true) {
    std::cout << "Waiting" << std::endl;
    acceptor();
    handler();
    responder();
    std::cout << "Done" << std::endl;

  }
}
