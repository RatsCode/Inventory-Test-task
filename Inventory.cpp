#include "Inventory.h"



void Inventory::add(Item* item)
{
	items.push_back(std::unique_ptr<Item>(item));
}

void Inventory::explore(const u_int& it)
{
	items[it]->info();
}
