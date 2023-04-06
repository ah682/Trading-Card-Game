// Adam James Anthony Hall
#include "CStudent.h"
#include "CEasyTarget.h"
#include "CCard.h"
#include "CCounter.h"
#include "CManager.h"


//Attacks Easy Target
int CEasyTarget::useCardSpecialAbility(int damage, vector <shared_ptr<CEasyTarget>>& attacked)
{
	unique_ptr<CCounter> pickRandom = make_unique<CCounter>();
	unique_ptr<CEasyTarget> cardType = make_unique<CEasyTarget>();

	if (attacked.size() > 0)
	{
		int randomIndex = pickRandom->Random(attacked.size() - 1);
		int attackedResilience = stoi(attacked[randomIndex]->mResilience);
		attackedResilience -= damage;

		if (attackedResilience > 0)
		{
			string attackedResilienceString = to_string(attackedResilience);
			cout << "Easy Target who was Attacked Resilience: " << attacked[randomIndex]->mResilience << endl;
		}
		if (attackedResilience <= 0)
		{
			
			cardType->activateCardDeath(randomIndex, attacked);
		}
	}
	if (attacked.size() <= 0 || attacked.empty())
	{
		//If there is no easy targets left do nothing
	}
	return damage;
}

void CEasyTarget::printCardUse()
{
	
}

void CEasyTarget::activateCardDeath(int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& attacked)
{
	cout << attacked[additionalEasyTargetRandomIndex]->mFirstname << attacked[additionalEasyTargetRandomIndex]->mLastname << " is defeated" << endl;
	cout << "Easy Target Killed" << endl;
	attacked.erase(attacked.begin() + additionalEasyTargetRandomIndex);
	
}

void CEasyTarget::attackEntity(int& additionalCardResilienceAttackedIntEasyTarget, int& leftOverDamage, int randomIndex, int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	additionalCardResilienceAttackedIntEasyTarget -= leftOverDamage;
	cout << "Left over damage attacks" << easyTarget[additionalEasyTargetRandomIndex]->mFirstname << easyTarget[additionalEasyTargetRandomIndex]->mLastname;
	string additionalCardResilienceAttackedStringEasyTarget = to_string(additionalCardResilienceAttackedIntEasyTarget);
	easyTarget[randomIndex]->mResilience = additionalCardResilienceAttackedIntEasyTarget;
}