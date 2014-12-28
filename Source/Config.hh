#pragma once

#include "json/json.hh"
#include <unordered_map>
#include <string>

namespace ss
{
	class Config
	{
	public:
		Config();

		// Just matching host to location so far
		static std::unordered_map<std::string, std::string> sites;

	private:
		void load_files();
		void parse_file(const Json::Value& root);
	};
}
