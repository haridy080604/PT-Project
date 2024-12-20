#include "CardSeven.h"
#include"RollDiceAction.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{

	cardNumber = 7;

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->GetOutput()->PrintMessage("Player " + to_string(pPlayer->getPlayerNumber()) + ": You will play again");
	pGrid->RollCurrentPlayer();
}

CardSeven::~CardSeven()
{

}
