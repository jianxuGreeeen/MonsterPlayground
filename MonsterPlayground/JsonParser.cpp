#include "JsonParser.h"
#include "JsonKeys.h"

using json = nlohmann::json;

void JsonParser::BuildCreatureDB(const json& arJson, CreatureDataBase& arOUT)
{
    arOUT.clear();

    auto itr = arJson.find(JsonKeys::Root);
    if (itr != arJson.end())
    {
        for (auto& creatureItr : itr->items())
        {
            const json creatureJson = creatureItr.value();
            CreatureDBPair pair;
            BuildCreatureDbPair(creatureJson, pair);
            arOUT.emplace(pair);
        }
    }
    else
    {
        throw std::runtime_error("Failed to find creature db");
    }
}

void JsonParser::BuildCreatureDbPair(const json& arJson, CreatureDBPair& arOUT)
{
    CreatureID& rid = arOUT.first;
    arJson.at(JsonKeys::Id).get_to(rid);

    CreatureData& rdata = arOUT.second;
    arJson.at(JsonKeys::Name).get_to(rdata.Name);

    auto itr = arJson.find(JsonKeys::BaseStats);
    if (itr != arJson.end())
    {
        const json statsJson = itr.value();
        BuildStats(statsJson, arOUT.second.Stats);
    }
    else
    {
        throw std::runtime_error("Failed to find base stats");
    }
}

void JsonParser::BuildStats(const json& arJson, CreatureStats& arOUT)
{
    arJson.at(JsonKeys::Hp).get_to(arOUT.HP);
    arJson.at(JsonKeys::Atk).get_to(arOUT.ATK);
    arJson.at(JsonKeys::Def).get_to(arOUT.DEF);
    arJson.at(JsonKeys::Satk).get_to(arOUT.SATK);
    arJson.at(JsonKeys::Sdef).get_to(arOUT.SDEF);
    arJson.at(JsonKeys::Spd).get_to(arOUT.SPD);
}
