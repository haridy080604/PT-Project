#include "CardNine.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

// Constructor
CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
    cardNumber = 9; // Set the card number
}

CardNine::CardNine()
{
}

// Reads the parameters of CardNine (the cell to move the player to)
void CardNine::ReadCardParameters(Grid* pGrid)
{
    // Get a Pointer to the Input/Output Interfaces from the Grid
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    // Ask the user to enter the cell to move the player to
    pOut->PrintMessage("Please Click on valid cell to be moved to .....");

    // Validate and store the cell position
    moveToCell = pIn->GetCellClicked();

    // Clear the status bar
    pOut->ClearStatusBar();
}

// Applies the effect of CardNine on the player who stops on it
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
    // Call the base class Apply to print the card's message
    Card::Apply(pGrid, pPlayer);

    // Inform the player about the move
    pGrid->PrintErrorMessage("Card 9: You will be moved to cell " + std::to_string(moveToCell.GetCellNum()) + ". Click to continue...");

    // Use the Player::Move function to move the player to the specific cell
    int stepsToMove = moveToCell.GetCellNum() - pPlayer->GetCell()->GetCellPosition().GetCellNum();
    if (stepsToMove > 0) // Move forward if necessary
    {
        pPlayer->Move(pGrid, stepsToMove);
    }
}

// Saves the card parameters to a file
void CardNine::Save(ofstream& OutFile, GameObjectsType Obj) const
{
    if (Obj == OBJ_CARD_9)
    {
        Card::Save(OutFile, Obj); // Save the base card info
        OutFile << moveToCell.GetCellNum() << std::endl; // Save the target cell number
    }
}

// Loads the card parameters from a file
void CardNine::Read(ifstream& InFile)
{
    Card::Read(InFile); // Read the base card info

    int cellNum;
    InFile >> cellNum; // Read the target cell number
    moveToCell = CellPosition::GetCellPositionFromNum(cellNum);
}

// Destructor
CardNine::~CardNine()
{
    // No dynamic memory to clean up
}
