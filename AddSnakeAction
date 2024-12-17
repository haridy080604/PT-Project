#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Grid And Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();




	///TODO: Make the needed validations on the read parameters

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on valid Start cell.....");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake :Please Click on valid End cell......");
	endPos = pIn->GetCellClicked();


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	//chekers
	//1-check the hcell to make sure equal each other
	//2-check start smaller than end
	if (startPos.HCell() != endPos.HCell()) {
		pManager->GetGrid()->PrintErrorMessage("End cell and start cell are not in the same column...");
		return;
	}
	else if (startPos.VCell() >= endPos.VCell()) {
		pManager->GetGrid()->PrintErrorMessage("End cell cannot be smaller than or equal to the start cell...");
		return;
	}

	// Create a Snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->IsOverLapping(pSnake)) {
		pGrid->PrintErrorMessage("Error Overlapping: Cell already has a Snake ! Click to continue ...");
		delete pSnake;
		return;
	}


	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		if (!added) {
			delete pSnake;
			pGrid->PrintErrorMessage("Invalid: Snake not added!");
		}
		else {
			pGrid->PrintErrorMessage("Snake added successfully!");
		}
		// Print an appropriate message
		/*delete pSnake;
		pGrid->PrintErrorMessage("InValid ...");*/

	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}
