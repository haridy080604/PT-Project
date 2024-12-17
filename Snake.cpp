#include "Snake.h"
#include "Output.h"
#include "Player.h"
#include "Input.h"
#include"Ladder.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	//check validation
	if (endCellPos.VCell() > this->position.VCell() && endCellPos.HCell() == this->position.HCell())
		this->endCellPos = endCellPos;

}
Snake::Snake() {
	this->endCellPos = CellPosition::GetCellPositionFromNum(1); //Default Constructor used in Open Grid

}


void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///DONE: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Print a Proper Message
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");

	// 2- Apply the Snake's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

bool Snake::IsOverlapping(GameObject* newObj) const
{
	if (this == newObj)
		return false;
	if (dynamic_cast<Ladder*>(newObj))
	{
		int h1 = position.HCell();
		int h2 = newObj->GetPosition().HCell();

		if (h1 == h2)
		{

			int StartCell1 = CellPosition::GetCellNumFromPosition(position);
			int EndCell1 = CellPosition::GetCellNumFromPosition(endCellPos);

			Ladder* pladder = (Ladder*)newObj;

			int StartCell2 = CellPosition::GetCellNumFromPosition(newObj->GetPosition());
			int EndCell2 = CellPosition::GetCellNumFromPosition(pladder->GetEndPosition());

			if (EndCell1 == StartCell2 || EndCell2 == StartCell1)

			{
				return true;
			}
		}

		return false;
	}



	if (dynamic_cast<Snake*>(newObj))
	{
		int h1 = position.HCell();
		int h2 = newObj->GetPosition().HCell();

		if (h1 == h2)
		{
			int StartCell1 = CellPosition::GetCellNumFromPosition(position);
			int EndCell1 = CellPosition::GetCellNumFromPosition(endCellPos);

			Snake* psnake = (Snake*)newObj;

			int StartCell2 = CellPosition::GetCellNumFromPosition(newObj->GetPosition());
			int EndCell2 = CellPosition::GetCellNumFromPosition(psnake->GetEndPosition());


			if (!((StartCell2 > StartCell1 && EndCell2 > StartCell1) || (StartCell2 < EndCell1 && EndCell2 < EndCell1)))
			{
				return true;
			}

		}


		return false;

	}

}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


Snake::~Snake()
{
}
