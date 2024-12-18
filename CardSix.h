#pragma once
#include"Card.h"

class CardSix : public Card
{

public:
	CardSix(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardSix();


};

