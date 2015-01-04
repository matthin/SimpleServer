#include "Client.hh"

#include <string>
#include "Socket.hh"
#include "http/Response.hh"
#include "http/Request.hh"
#include "methods/Get.hh"
#include "Config.hh"

ss::Client::Client(Socket* socket) : socket(socket)
{
	auto request = get_request();
	http::Response response;
	response.headers["protocol"] = "HTTP/1.1";

	if (request.headers["method"] == "GET")
	{
		methods::Get(request, &response);
	}

	send_response(response);
}

ss::http::Request ss::Client::get_request()
{
	std::string response;

	// An endless wait may happen if the last response is the same size as buffer.
	while (true)
	{
		char buffer[1024];
		int received;
		socket->receive(&buffer, sizeof(buffer), &received);
		response.append(buffer, received);

		if (received < sizeof(buffer))
		{
			break;
		}
	}

	return http::Request(response);
}

void ss::Client::send_response(const http::Response& response)
{
	const auto response_string = response.as_string();
	socket->send(response_string.data(), response_string.size());
	socket->disconnect();
}
