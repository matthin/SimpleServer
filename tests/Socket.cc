#include "catch.hpp"

#include "Socket.hh"
#include "Listener.hh"
#include <string>

TEST_CASE("Sends and receives data")
{
	ss::Listener listener;
	listener.listen(8080);

	ss::Socket socket;
	if (listener.accept(&socket))
	{
		std::string message("Just a test");
		socket.send(message.data(), message.size());

		
	}
}
