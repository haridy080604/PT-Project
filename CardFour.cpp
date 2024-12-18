#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{

	int card_number = 4;

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	


	/*if (pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition()) != NULL)
	{
		pGrid->UpdatePlayerCell(pPlayer, pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition())->GetPosition());



	}

*/

}

CardFour::~CardFour()
{


}