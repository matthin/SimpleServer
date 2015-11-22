#pragma once

#include "Client.hh"
#include <rokunet/Socket.h>
#include <rokunet/Listener.h>
#include <thread>
#include <vector>
#include <memory>
#include <mutex>

namespace ss {
class Server {
public:
  Server(unsigned short port);

private:
  rokunet::Socket socket;
  rokunet::Listener listener;
};
}
