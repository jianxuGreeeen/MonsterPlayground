#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#pragma once
#include <string>
#include "json.hpp"

namespace JsonLoaders
{
	bool ReadJson(const std::string& arFileName, nlohmann::json& arOUT);

};

#endif // JSON_LOADER_H

