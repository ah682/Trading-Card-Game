// Adam James Anthony Hall

// Initialize necessary header files
#include "CCard.h"

void CCard::printCardUse()
{
	cout << "Card" << endl;
}

void CCard::activateCardDeath()
{
	cout << "Activating Card Death" << endl;
}

void CCard::useCard()
{

}

int CCard::useCardSpecialAbility() // Gets returned value such as damage to pass to professor or entities
{

	return 0;
}

void CCard::attackProfessor()
{
	cout << "Let's keep going" << endl;
}

void CCard::attackEntity()
{
	cout << "Attacking Entity" << endl;
}