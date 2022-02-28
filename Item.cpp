#include "Item.h"



Item::Item(const	std::string&	ident,
					Type			type,
					u_int			level,
					Rarity			rarity)
	:
	_ident(ident) 
{
	filters.push_back(filter_pair("type",	static_cast<u_int>(type)	));
	filters.push_back(filter_pair("level",	level						));
	filters.push_back(filter_pair("rarity", static_cast<u_int>(rarity)	));
};



Weapon::Weapon(	Buffs&			buffs,
				std::string		ident,
				Type			type,
				u_int			level,
				Rarity			rarity,
				double			damage,
				double			speed)

	:
	Item(ident, type, level, rarity)

{
	params.push_back(param_pair(AllowedBuffs::damageBuff,	damage	));
	params.push_back(param_pair(AllowedBuffs::speedBuff,	speed	));

	buffs.apply_buffs(params, filters);
}

void Weapon::info()
{
	std::cout	<< "This is \"" << _ident << "\" with "
				<< params[static_cast<int>(stat::damage)].second << " damage and "
				<< params[static_cast<int>(stat::speed)].second  << " speed" << std::endl;
}



Armour::Armour(	Buffs&			buffs,
				std::string		ident,
				Type			type,
				u_int			level,
				Rarity			rarity,
				double			armour)
	:
	Item(ident, type, level, rarity)

{
	params.push_back(param_pair(AllowedBuffs::protectionBuff, armour));

	buffs.apply_buffs(params, filters);
}

void Armour::info()
{
	std::cout << "This is \"" << _ident << "\" with "
		<< params[static_cast<int>(stat::armour)].second << " protection" << std::endl;
}
