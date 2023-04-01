// Adam James Anthony Hall
#include "CMitigatingCircumstances.h"

int CMitigatingCircumstances::grantDamageReduction(int damage, int mDamageReduction)
{
	damage += mDamageReduction;
	return damage;
}

void CMitigatingCircumstances::printCardUse()
{
	std::cout << "You have used Mitigating Circumstances. You have gained 1 damage reduction." << std::endl;
}

void CMitigatingCircumstances::printCardDeath()
{
	std::cout << "You have been killed by Mitigating Circumstances. You have lost 1 damage reduction." << std::endl;
}