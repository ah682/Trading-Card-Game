#pragma once

#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

#include "CCard.h"
#include "CPlayers.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCounter.h"

class CManager
{
public:
    void startRound(int round);
    void gameStart();
    void gameOver(CPlayers::SProfessor winner, CPlayers::SProfessor loser);
    void cardsDuel(vector<shared_ptr<CCard>>& table, vector<shared_ptr<CCard>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardDrawn, int randomCard, int& typeFiveCounter);
    void cardsDuelCards();
    void fillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent);
    void drawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<shared_ptr<bool>>& usedCards);
    void tableCard(vector<shared_ptr<CCard>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard);
    void plagiarismHearing(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCard>>& plagiarism, vector<shared_ptr<CCard>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice);
    void courseAccreditation(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCard>>& accreditation, vector<shared_ptr<CCard>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName);
    void feedbackForum(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CCard>>& feedbackforum, vector<shared_ptr<CCard>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CCard>>& tableAttacker);
    void industrialPlacement();

};
