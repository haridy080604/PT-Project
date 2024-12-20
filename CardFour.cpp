#include "CardFour.h"
#include"Snake.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos)
{

	cardNumber = 4;

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int current_pos = pPlayer->GetCell()->GetCellPosition().GetCellNum();



	if (pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition()) != NULL)
	{
		pPlayer->Move(pGrid, pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition())->GetPosition().GetCellNum() - current_pos);
		//pGrid->UpdatePlayerCell(pPlayer, pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition())->GetPosition());



	}



}

CardFour::~CardFour()
{


}
