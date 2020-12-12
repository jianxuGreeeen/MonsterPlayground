#include "JsonLoaders.h"

#include <fstream>

namespace JsonLoaders
{
	bool ReadJson(const std::string& arFileName, nlohmann::json& arOUT)
	{
		arOUT.clear();

		bool success = false;

		std::ifstream i(arFileName);
		if (i.is_open())
		{
			i >> arOUT;
			success = !i.bad() && !i.fail();
		}

		return success;
	}
}

