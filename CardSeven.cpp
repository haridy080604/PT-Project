#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{

	cardNumber = 7;

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());







}

CardSeven::~CardSeven()
{

}
