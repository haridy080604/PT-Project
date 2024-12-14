#include "Ladder.h"
#include "Output.h"
#include "Player.h"
#include "Input.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	//check validation
	if (endCellPos.VCell() < this->position.VCell() && endCellPos.HCell() == this->position.HCell())
		this->endCellPos = endCellPos;

}
Ladder::Ladder() {
	this->endCellPos = CellPosition::GetCellPositionFromNum(1); //Default Constructor used in Open Grid

}


void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///DONE: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Print a Proper Message
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_LADDER) // check if Obj is Ladder
	{
		GameObject::Save(OutFile, Obj); //print the start Position of Ladder 
		OutFile << GetEndPosition().GetCellNum() << '\n'; // print the The end Positon of ladder
	}
}

GameObject* Ladder::Load(ifstream& InFile) {

	GameObject::Load(InFile);

	int  endPosCellNum;

	InFile >> endPosCellNum; //read

	endCellPos = CellPosition::GetCellPositionFromNum(endPosCellNum);
	return this;
}


Ladder::~Ladder()
{
}
