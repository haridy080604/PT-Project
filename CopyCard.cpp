#include "CopyCard.h"
#include "Grid.h"
CopyCard::CopyCard(ApplicationManager* pApp): Action(pApp) {}

void CopyCard::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	c = pIn->GetCellClicked();
}
void  CopyCard::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->getCopy(c);
}

CopyCard::~CopyCard() {

 }