#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{

	cardNumber = 6;

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->Move(pGrid, -pPlayer->GetJustRolledDiceNum());





}

CardSix::~CardSix()
{

}
