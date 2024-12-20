#include "CardThree.h"
#include"Ladder.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos)
{

	cardNumber = 3;

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int dice_number = 0;
	int current_pos = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	Ladder* pLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());


	if (pLadder != NULL)
	{
		pPlayer->Move(pGrid, pLadder->GetPosition().GetCellNum() - current_pos);
		//pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());


	}



}

CardThree::~CardThree()
{


}
