#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp) {

}

void NewGameAction::ReadActionParameters() {

}

void NewGameAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	int mxPlayer = MaxPlayerCount;
	CellPosition c(1);
	Player* p = pGrid->GetCurrentPlayer();
	for (int i = 0; i < mxPlayer; i++) {
		p->SetWallet(100);
		pGrid->UpdatePlayerCell(p, c);
		pGrid->AdvanceCurrentPlayer();
	}
	p->SetTurnCount(0);
}

NewGameAction:: ~NewGameAction() {}