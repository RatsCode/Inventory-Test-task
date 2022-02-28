#pragma once
#include "includes.h"

#define BUFF_COUNTER 3



class Buffs
{
public:
	Buffs();

	void apply_buffs(std::vector<param_pair>&	params,
					 std::vector<filter_pair>&	filters);

private:
	class buff
	{
	public:
		buff();

		
		AllowedBuffs				_buff_type;
		std::string					_ident;
		double						_value;
		std::vector<filter_pair>	_filters;
	};


	buff buffs[BUFF_COUNTER];
};