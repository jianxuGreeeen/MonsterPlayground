#pragma once

#include <cstdint>
#include <map>
#include <string>

//TODO: Movesets
//TODO: Elements

using HealthStat		= uint8_t;
using SpeedStat			= uint8_t;
using AttackStat		= uint8_t;
using DefenseStat		= uint8_t;
using SpecialAtkStat	= uint8_t;
using SpecialDefStat	= uint8_t;
using IndividualValue	= uint8_t;

struct CreatureStats final
{
	CreatureStats(HealthStat aHP
		, SpeedStat			aSPD
		, AttackStat		aATK
		, DefenseStat		aDEF
		, SpecialAtkStat	aSATK
		, SpecialDefStat	aSDEF) :
		HP(aHP), SPD(aSPD), ATK(aATK), DEF(aDEF), SATK(aSATK), SDEF(aSDEF) {}

	HealthStat		HP		= 0;
	SpeedStat		SPD		= 0;
	AttackStat		ATK		= 0;
	DefenseStat		DEF		= 0;
	SpecialAtkStat	SATK	= 0;
	SpecialDefStat	SDEF	= 0;
};

class CreatureData final
{
public:
	CreatureStats	Stats	= { 0,0,0,0,0,0 };
	std::string		Name	= "";
};

using CreatureID = uint64_t;
using CreatureDataBase = std::map<CreatureID, CreatureData>;

