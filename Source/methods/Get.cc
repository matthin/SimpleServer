#include "Get.hh"

#include <fstream>

ss::methods::Get::Get(const std::string& location, http::Response* response)
{
	auto file = read_file(location.substr(1));
	if (file.empty())
	{
		response->headers["code"] = "404";
		response->headers["code_message"] = "Not Found";
		response->headers["Content-Length:"] = 15;
		response->message = "404 - Not Found";
	}
	else
	{
		response->headers["Content-Type"] = mime_type(location);
		response->headers["code"] = "200";
		response->headers["code_message"] = "OK";
		response->headers["Content-Length:"] = file.size();
		response->message = file;
	}
}

std::string ss::methods::Get::mime_type(const std::string& location)
{
	auto split_pos = location.find_last_of('.');
	if (split_pos == std::string::npos)
	{
		return "text/plain";
	}
	else
	{
		auto extention = location.substr(split_pos + 1);

		// For testing purposes
		if (extention == "cc")
		{
			return "text/html";
		}
		else
		{
			return "text/plain";
		}
	}
}

std::string ss::methods::Get::read_file(const std::string& location)
{
	std::ifstream file(location);
	if (!file.is_open())
	{
		return "";
	}

	file.seekg(0, std::ios::end);
	auto size = file.tellg();
	std::string contents(static_cast<unsigned int>(size), ' ');
	file.seekg(0, std::ios::beg);
	file.read(&contents[0], size);

	return contents;
}
