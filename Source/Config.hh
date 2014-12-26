#pragma once

#include "json/json.hh"

namespace ss
{
	class Config
	{
	public:
		Config();

	private:
		void load_files();
		void parse_file(const Json::Value& root);
	};
}
