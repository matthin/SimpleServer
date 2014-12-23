#pragma once

#include <string>
#include "http/Response.hh"

namespace ss
{
	namespace methods
	{
		class Get
		{
		public:
			Get(const std::string& location, http::Response* response);

		private:
			std::string mime_type(const std::string& location);
			std::string read_file(const std::string& location);
		};
	}
}
