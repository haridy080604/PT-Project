#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp) {

}
void InputDiceValueAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("please enter a dice value between 1-6");
	Output* pOut = pGrid->GetOutput();
	diceNumber = pIn->GetInteger(pOut);
}
void InputDiceValueAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	if (!(pGrid->GetCurrentPlayer()->GetFreeze()))
	{
		ReadActionParameters();
		if (diceNumber < 7 && diceNumber > 0) {
			if (!pGrid->GetEndGame()) {
				pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);
				pGrid->AdvanceCurrentPlayer();
			}
		}
		else {
			pGrid->PrintErrorMessage("Wrong Dice Number");
		}
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("Played Disallowd");
		pGrid->AdvanceCurrentPlayer();
		pGrid->GetCurrentPlayer()->setFreeze(false);
		int increment = (pGrid->GetCurrentPlayer()->GetTurnCount()) + 1;
		pGrid->GetCurrentPlayer()->SetTurnCount(increment);
	}
}
InputDiceValueAction::~InputDiceValueAction() {

}
