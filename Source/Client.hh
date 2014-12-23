#pragma once

#include "Socket.hh"
#include "http/Request.hh"
#include "http/Response.hh"

#include <memory>

namespace ss
{
	class Client
	{
	public:
		Client(Socket* socket);
		http::Request get_request();
		void send_response(const http::Response& response);

	private:
		std::unique_ptr<Socket> socket;
	};
}
