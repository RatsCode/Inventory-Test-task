#pragma once
#include "Item.h"

class Inventory
{
public:
	void add(Item* item);

	u_int get_quantity() { return items.size(); };

	void explore(const u_int& it);

private:
	std::vector<std::unique_ptr<Item>> items;
};

