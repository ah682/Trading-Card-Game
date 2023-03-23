// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include <fstream>
#include <vector>

#include "CCard.h"
#include "CPlayers.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCounter.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"

class CManager
{
public:
	void GameStart();
	void GameOver(CPlayers::SProfessor winner, CPlayers::SProfessor loser);
	void StartRound(int round);
	void UseStudentCard(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardDrawn, int randomCard, int& typeFiveCounter);
	void FillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent);
	void DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<shared_ptr<bool>>& usedCards);
	void PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard);
	void UsePlagiarismHearingCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice);
	void UseCourseAccreditationCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName);
	void UseFeedbackForumCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker);
};

