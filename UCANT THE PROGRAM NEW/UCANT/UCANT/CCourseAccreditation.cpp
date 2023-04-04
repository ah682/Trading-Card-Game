// Adam James Anthony Hall

// Initialize necessary header files
#include "CCourseAccreditation.h"

void CCourseAccreditation::useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CCourseAccreditation> printCardType = make_unique<CCourseAccreditation>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();


	const int CARD_POWER = 1;
	int cardResilience = 0;

	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_COURSE_ACCREDITATION && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CCourseAccreditation> pAccreditationElement = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(pAccreditationElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	for (int i = 0; i < accreditation.size(); i++)
	{
		if (!tableAttacked.empty()) {
			for (int j = 0; j < tableAttacked.size() - 1; j++)
			{
				activateEasyTarget->useCardSpecialAbility(CARD_POWER, easyTarget);
				cardResilience = stoi(tableAttacked[j]->mResilience);
				cardResilience -= CARD_POWER;
				string cardResilienceString = to_string(cardResilience);
				tableAttacked[j]->mResilience = cardResilienceString;
				cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks : " << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " resilience is now " << tableAttacked[j]->mResilience << endl;


				if (cardResilience <= 0) {
					printCardType->activateCardDeath(j, tableAttacked);
				}
			}

			printCardType->attackProfessor(CARD_POWER, randomCard, professorAttacked, cardsDrawn);

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}

	}
}


void CCourseAccreditation::printCardUse()
{
	cout << "Using Course Accreditation Card" << endl;
}

void CCourseAccreditation::activateCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked)
{
	tableAttacked[j]->mResilience = "0";
	cout << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " is defeated" << endl;
	tableAttacked[j]->mResilience = G_DEAD_CARD;
	tableAttacked.erase(tableAttacked.begin() + j);
}

void CCourseAccreditation::attackProfessor(int cardPower, int randomCard, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>>& cardsDrawn)
{
	professorAttacked.mProfPrestige -= cardPower;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks : " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}