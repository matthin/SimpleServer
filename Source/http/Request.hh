#pragma once

#include <string>
#include <unordered_map>

namespace ss
{
	namespace http
	{
		class Request
		{
		public:
			Request(const std::string& headers_string);
			std::unordered_map<std::string, std::string> headers;

		private:
			void parse_headers(const std::string& headers_string);
		};
	}
}
