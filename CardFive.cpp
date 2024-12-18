#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{

	int card_number = 5;

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());





}

CardFive:: ~CardFive()
{

}