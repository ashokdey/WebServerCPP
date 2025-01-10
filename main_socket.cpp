#include <iostream>
#include "networking/lib/socket/socket.hpp"
#include "networking/lib/listening_socket/listening_socket.hpp"
#include "networking/lib/binding_socket/binding_socket.hpp"

int main() 
{

  std::cout << "Starting..." << std::endl;
  std::cout << "Binding socket..." << std::endl;

  AD::BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);

  std::cout << "Listening socket..." << std::endl;

  AD::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
}