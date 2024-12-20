#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp) {

}
void PasteCardAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	c = pIn->GetCellClicked();
}

void PasteCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetClipboard()) {
		pGrid->GetClipboard()->setPosition(c);
		pGrid->AddObjectToCell(pGrid->GetClipboard());
	}
}

PasteCardAction::~PasteCardAction() {

}
