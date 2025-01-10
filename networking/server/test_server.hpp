#ifndef test_server_hpp
#define test_server_hpp 

#include <stdio.h>
#include "server.hpp"

namespace AD 
{
  class TestServer: public Server 
  {
    private:
      char buffer[30000] = {0};
      int new_socket;

      void acceptor();
      void handler();
      void responder();

    public:
      TestServer();
      void launch();
  };
}

#endif