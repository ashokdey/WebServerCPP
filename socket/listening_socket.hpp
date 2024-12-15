#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

namespace AD 
{
  class ListeningSocket 
  {
    private:
      int backlog;
      int listening;
      
    public: 
      ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog);



  }
}

#endif