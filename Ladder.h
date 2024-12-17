
#ifndef LADDER
#define LADDER


#include "Grid.h"
#include "GameObject.h"
#include<fstream>
using namespace std;

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization
	Ladder(); //default constructor used in OpenGrid 
			  //set some default values to card as position = endCellPos = CellPosition(1) -> first Cell in Grid
	

	
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell
	bool IsOverlapping(GameObject* newObj) const override;


	
	CellPosition GetEndPosition() const; // A getter for the endCellPos data member


	virtual ~Ladder(); // Virtual destructor
};

#endif
