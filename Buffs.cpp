#include "Buffs.h"



//typedef unsigned int						u_int;
//typedef std::pair<std::string, u_int>		filter_pair;
//typedef std::pair<AllowedBuffs, double>	param_pair;



void Buffs::apply_buffs(std::vector<param_pair>&	params,
						std::vector<filter_pair>&	filters)
{
	for (auto& parametr : params)
	{
		for (int i = 0; i < BUFF_COUNTER; ++i)
		{

			if (buffs[i]._buff_type == parametr.first)
			{
				bool no_match = true;
				auto it = buffs[i]._filters.begin();

				// compare by item type
				for (; it != buffs[i]._filters.end(); ++it)
				{
					if (filters[0].first == (*it).first)
					{
						if (filters[0].second == (*it).second)
						{
							no_match = false;
							++it;
							break;
						}
					}
					else
					{
						break;
					}
				}

				if (no_match)
				{
					continue;
				}
				else
				{
					no_match = true;
				}


				// compare by level
				for (; it != buffs[i]._filters.end(); ++it)
				{
					if (filters[1].first == (*it).first)
					{
						if (filters[1].second >= (*it).second)
						{
							no_match = false;
							++it;
							break;
						}
					}
				}

				if (no_match)
				{
					continue;
				}
				else
				{
					no_match = true;
				}


				// compare by rarity
				for (; it != buffs[i]._filters.end(); ++it)
				{
					if (filters[2].first == (*it).first)
					{
						if (filters[2].second >= (*it).second)
						{
							no_match = false;
							++it;
							break;
						}
					}
				}

				if (no_match)
				{
					continue;
				}
				else
				{
					parametr.second += buffs[i]._value;
				}
			}

		}
	}
}

Buffs::buff::buff()
	:
	_ident(),
	_value(0),
	_buff_type(),
	_filters()
{}

Buffs::Buffs()
{
	buffs[0]._buff_type	= AllowedBuffs::damageBuff;
	buffs[0]._ident		= "eagle_eye";
	buffs[0]._value		= 10;
	buffs[0]._filters.push_back(filter_pair("type",		static_cast<u_int>(Type::range)		));
	buffs[0]._filters.push_back(filter_pair("level",	4									));
	buffs[0]._filters.push_back(filter_pair("rarity",	static_cast<u_int>(Rarity::common)	));



	buffs[1]._buff_type	= AllowedBuffs::protectionBuff;
	buffs[1]._ident		= "donatium_steel";
	buffs[1]._value		= 15;
	buffs[1]._filters.push_back(filter_pair("type",		static_cast<u_int>(Type::armour)	));
	buffs[1]._filters.push_back(filter_pair("level",	0									));
	buffs[1]._filters.push_back(filter_pair("rarity",	static_cast<u_int>(Rarity::rare)	));



	buffs[2]._buff_type = AllowedBuffs::speedBuff;
	buffs[2]._ident		= "rage_drink";
	buffs[2]._value		= 0.4;
	buffs[2]._filters.push_back(filter_pair("type",		static_cast<u_int>(Type::range)		));
	buffs[2]._filters.push_back(filter_pair("type",		static_cast<u_int>(Type::melee)		));
	buffs[2]._filters.push_back(filter_pair("level",	0									));
	buffs[2]._filters.push_back(filter_pair("rarity",	static_cast<u_int>(Rarity::common)	));
}
