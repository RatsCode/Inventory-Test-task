#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>



enum class Type
{
	melee = 1,
	range,
	armour
};

enum class Rarity
{
	common = 1,
	rare,
	epic
};

enum class AllowedBuffs
{
	damageBuff = 1,
	speedBuff,
	protectionBuff
};


typedef unsigned int					u_int;
typedef std::pair<std::string, u_int>	filter_pair;
typedef std::pair<AllowedBuffs, double>	param_pair;