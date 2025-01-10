#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


namespace AD {
  class Socket {
    private:
    int sck;
    struct sockaddr_in address;

    public:
      Socket(int domain, int service, int protocol, int port, u_long interface);

      virtual void connect_to_network(
        int sck, struct sockaddr_in address
      ) = 0;

      void test_connection(int entity);
      struct sockaddr_in get_address();
      int get_socket();

  };
}

#endif