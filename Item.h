#pragma once
#include "includes.h"
#include "Buffs.h"



//typedef unsigned int						u_int;
//typedef std::pair<std::string, u_int>		filter_pair;
//typedef std::pair<AllowedBuffs, double>	param_pair;

class Buffs;


class Item
{
public:
	Item(const	std::string&	ident	=	"", 
				Type			type	=	Type::melee,
				u_int			level	=	1,
				Rarity			rarity	=	Rarity::common);

	virtual void info() {};

protected:
	std::string	_ident;

	std::vector<filter_pair>	filters;
	std::vector<param_pair>		params;
};



class Weapon : public Item
{
public:
	Weapon(		  Buffs&		buffs,
			const std::string&	ident,
				  Type			type	=	Type::melee,
				  u_int			level	=	1,
				  Rarity		rarity	=	Rarity::common,
				  double		damage	=	1,
				  double		speed	=	1);

	void info() override;

private:
	enum class stat
	{
		damage	= 0,
		speed	= 1
	};
};


class Armour : public Item
{
public:
	Armour(		  Buffs&		buffs,
			const std::string&	ident,
				  Type			type	=	Type::armour,
				  u_int			level	=	1,
				  Rarity		rarity	=	Rarity::common,
				  double		armour	=	1);

	void info() override;

private:
	enum class stat
	{
		armour = 0
	};
};