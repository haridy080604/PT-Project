#include "DeleteGameObject.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp) {};
void DeleteGameObject::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	c = pIn->GetCellClicked();
}
void DeleteGameObject::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(c);
	pGrid->PrintErrorMessage("Delete the object");
}
DeleteGameObject::~DeleteGameObject() {}
