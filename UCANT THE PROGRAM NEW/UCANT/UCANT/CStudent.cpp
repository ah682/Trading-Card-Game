// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CEasyTarget.h"
#include "CCard.h"

int CStudent::grantDamageReduction(int damage, int mDamageReduction)
{
	damage += mDamageReduction;
	return damage;
}

int CStudent::attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>> attacked)
{
	return damage;
}