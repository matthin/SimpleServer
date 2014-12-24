#pragma once

#include <string>

namespace ss
{
	class Config
	{
	public:
		Config();

	private:
		void load_files();
	};
}
