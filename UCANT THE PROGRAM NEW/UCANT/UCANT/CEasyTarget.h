// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CCounter.h"
class CEasyTarget :
    public CCard
{
    public:
    int attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>>& attacked);
    
};

