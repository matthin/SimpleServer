#include "catch.hpp"

#include "Socket.hh"
#include "Listener.hh"
#include <string>

TEST_CASE("Communicates")
{
	ss::Listener listener;
	listener.listen(8082);

	ss::Socket client;
	client.connect("127.0.0.1", 8082);

	ss::Socket socket;
	listener.accept(&socket);

	std::string message("Just a test");
	socket.send(message, message.size());

	char buffer[message.size()];
	int received;
	client.receive(&buffer, sizeof(buffer), &received);

	REQUIRE(received == message.size());
	REQUIRE(std::string(buffer, received) == message);
}
