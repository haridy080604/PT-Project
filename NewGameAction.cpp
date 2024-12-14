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
	Player* p = pGrid->GetCurrentPlayer();
	for (int i = 0;i < mxPlayer;i++) {
		p->SetWallet(100);
		pGrid->UpdatePlayerCell(p, pGrid->GetStartCell());
		pGrid->AdvanceCurrentPlayer();
	}
	p->setTurnCount(0);
}

NewGameAction:: ~NewGameAction() {}