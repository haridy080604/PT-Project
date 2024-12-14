#include "Switch_To_Play_Mode.h"
#include "Output.h"
#include "Grid.h"
Switch_To_Play_Mode::Switch_To_Play_Mode(ApplicationManager* App):Action(App)
{
}
void Switch_To_Play_Mode::ReadActionParameters()
{
	//No Need 
}

void Switch_To_Play_Mode::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	pOut->CreatePlayModeToolBar();

	//pGrid->forexample:resetGame();

}

Switch_To_Play_Mode::~Switch_To_Play_Mode()
{
}

