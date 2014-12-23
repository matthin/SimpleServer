#pragma once

#include "Socket.hh"
#include "Listener.hh"
#include "Client.hh"
#include <thread>
#include <vector>
#include <memory>
#include <mutex>

namespace ss
{
	class Server
	{
	public:
		Server(unsigned short port);

	private:
		Socket socket;
		Listener listener;
	};
}
