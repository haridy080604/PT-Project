#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos)
{

	cardNumber = 3;

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int dice_number = 0;
	int current_pos = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	GameObject* pObject = (GameObject*)pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());


	if (pObject != NULL)
	{
		pGrid->UpdatePlayerCell(pPlayer, pObject->GetPosition());



	}



}

CardThree::~CardThree()
{


}
