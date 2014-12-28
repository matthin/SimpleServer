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
		const auto host = request.headers["Host"];
		// Check if Host header contains a port.
		const auto port_pos = host.find_last_of(":");
		if (port_pos == std::string::npos)
		{
			methods::Get(Config::get_sites()[host] + request.headers["location"], &response);
		}
		else
		{
			methods::Get(Config::get_sites()[host.substr(0, port_pos)] + request.headers["location"], &response);
		}
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
