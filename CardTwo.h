#pragma once

#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Increments the value of the passing player’s wallet by a value


class CardTwo : public Card
{
	// CardOne Parameters:
	int walletAmount;// the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by incrementing the player's wallet by the walletAmount data member

	virtual ~CardTwo(); // A Virtual Destructor
};

