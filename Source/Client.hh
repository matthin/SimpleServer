#pragma once

#include <rokunet/Socket.h>
#include <rokunet/Http/Request.h>
#include <rokunet/Http/Response.h>
#include <memory>

namespace ss {
class Client {
public:
  Client(rokunet::Socket *socket);
  rokunet::Http::Request get_request();

private:
  std::unique_ptr<rokunet::Socket> socket;
};
}
