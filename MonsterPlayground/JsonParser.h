#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#pragma once
#include "CommonTypes.h"
#include "json.hpp"

namespace JsonParser
{
	void BuildCreatureDB(const nlohmann::json& arJson, CreatureDataBase& arOUT);
	void BuildCreatureDbPair(const nlohmann::json& arJson, CreatureDBPair& arOUT);
	void BuildStats(const nlohmann::json& arJson, CreatureStats& arOUT);
};
#endif // JSON_PARSER_H

