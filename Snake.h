#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	CellPosition endCellPos; // here is the snake's End Cell Position

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization
	Snake(); //default constructor used in OpenGrid 
	//set some default values to card as position = endCellPos = CellPosition(1) -> first Cell in Grid


	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to snakes's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	bool IsOverlapping(GameObject* newObj) const override;



	virtual ~Snake(); // Virtual destructor
};


