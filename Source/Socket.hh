#pragma once

#include <sys/socket.h>
#include <netinet/in.h>

#include <string>

namespace ss {
class Socket {
public:
  Socket();
  ~Socket();

  void send(const std::string &data, unsigned int size);
  void receive(void *data, int size, int *received);

  bool connect(const std::string &host, const unsigned short port);
  bool disconnect();

  void set_timeout(long seconds, long microseconds);
  void set_timeout(long seconds);

  std::string get_remote_address();
  unsigned short get_local_port();

  int handle;

protected:
  sockaddr_in create_address(const std::string &host, unsigned short port);
};
}
