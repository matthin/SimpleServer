#include "Config.hh"

#include "json/json.hh"
#include <fstream>
#include <vector>

ss::Config::Config()
{
	load_files();
}

void ss::Config::load_files()
{
	Json::Reader reader;
	Json::Value root;

	std::ifstream files;
	files.open("../../Files.json");
	reader.parse(files, root);

	std::vector<std::string> locations_list;
	for (const auto& location : root["files"])
	{
		locations_list.push_back(location.asString());
	}
}
