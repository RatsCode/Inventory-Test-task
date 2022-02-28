#include "Inventory.h"



int main()
{
	Inventory inventory;
	Buffs buffs;

	inventory.add(new Weapon(buffs, "axe_01",				Type::melee,  3, Rarity::common, 12.0, 0.9 ));
	inventory.add(new Weapon(buffs, "revolver_01",			Type::range,  5, Rarity::common, 42.0, 2.0 ));
	inventory.add(new Weapon(buffs, "revolver_02",			Type::range,  3, Rarity::rare,   50.0, 2.1 ));
	inventory.add(new Weapon(buffs, "machinegun_01",		Type::range,  5, Rarity::epic,   83.1, 10.0));
	inventory.add(new Armour(buffs, "jacket_01",			Type::armour, 2, Rarity::common, 2.0 ));
	inventory.add(new Armour(buffs, "bulletprof_vest_01",	Type::armour, 5, Rarity::rare,   30.0));


	for (u_int i = 0; i < inventory.get_quantity(); ++i)
	{
		inventory.explore(i);
	}


	std::cout << std::endl << "Have a nice day" << std::endl;
	system("pause");
}