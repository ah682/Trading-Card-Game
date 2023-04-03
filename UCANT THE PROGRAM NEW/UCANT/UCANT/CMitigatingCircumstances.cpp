// Adam James Anthony Hall
#include "CMitigatingCircumstances.h"

int CMitigatingCircumstances::grantDamageReduction(int damage, int mDamageReduction)
{
	damage += mDamageReduction;
	return damage;
}

void CMitigatingCircumstances::useCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard)
{
	unique_ptr<CMitigatingCircumstances> printCardType = make_unique<CMitigatingCircumstances>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_MITIGATING_CIRCUMSTANCES && (cardsDrawn[randomCard]->mType != G_DEAD_CARD))
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CMitigatingCircumstances> pMitigatingCircumstancesElement = static_pointer_cast<CMitigatingCircumstances>(cardsDrawn[randomCard]);

			// Add the converted element to the accreditation vector
			mitigatingCircumstances.push_back(pMitigatingCircumstancesElement);
		}
	}
	else
	{
		cout << "randomCard is out of range" << endl;
	}

	for (int i = 0; i < mitigatingCircumstances.size(); i++)
	{
		int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
		if (randomIndex < tableAttacker.size())
		{
			if (!mitigatingCircumstances.empty())
			{
				if (!tableAttacker.empty())
				{
					if (randomIndex < tableAttacker.size())
					{
						int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
						int tableAttackerResillienceInt = stoi(tableAttacker[randomIndex]->mResilience);
						if (damageReduction != nullptr) {
							int damageReductionGranted = damageReduction->grantDamageReduction(tableAttackerResillienceInt, damageReduction->mDamageReduction);
							string damageReductionString = to_string(damageReductionGranted);
							tableAttacker[randomIndex]->mResilience = damageReductionString;
							cout << "Damaged Reduced of card" << tableAttacker[randomIndex]->mType << tableAttacker[randomIndex]->mFirstname << tableAttacker[randomIndex]->mLastname << tableAttacker[randomIndex]->mPower << tableAttacker[randomIndex]->mResilience << tableAttacker[randomIndex]->mBoost << endl;
						}
						else {
							// skip the function or handle the null pointer case
						}

					}
					else
					{

					}
				}
			}

			if (tableAttacker.empty())
			{
				cout << "Table attacker is empty!" << endl;
			}
		}
	}
	if (mitigatingCircumstances.empty())
	{
		cout << "There is no mitigating circumstance cards to use" << endl;
	}
}

void CMitigatingCircumstances::printCardUse()
{
	cout << "Using Mitigiating Circumstances Card" << endl;
}

void CMitigatingCircumstances::printCardDeath()
{
	std::cout << "You have been killed by Mitigating Circumstances. You have lost 1 damage reduction." << std::endl;
}