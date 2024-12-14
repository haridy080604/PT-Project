#include "Switch_To_Design_Mode.h"
#include"Output.h"
#include "Grid.h"
Switch_To_Design_Mode::Switch_To_Design_Mode(ApplicationManager* App) :Action(App)
{

}

void Switch_To_Design_Mode::ReadActionParameters()
{
	//No Need
}

void Switch_To_Design_Mode::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	pOut->CreateDesignModeToolBar();

	//pGrid->forexample:resetGame();
}

Switch_To_Design_Mode::~Switch_To_Design_Mode()
{

}

