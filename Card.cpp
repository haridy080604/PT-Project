#include "Card.h"
#include"Input.h"
#include"CellPosition.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"

Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

Card::Card() {
	//Default Constructor Use In OpenGridAction
}

void Card::SetCardNumber(int cnum)
{
	// check the validation 
	if (cardNumber > 0 && cardNumber <= 13)
		cardNumber = cnum;
}

int Card::GetCardNumber() const { return cardNumber; }

void Card::Draw(Output* pOut) const
{
	///DONE: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);
}

void Card::ReadCardParameters(Grid* pGrid)
{

	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	//print proper Message 
	//this will be overridden by all cards
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ", Click to continue ...");
}




Card::~Card()
{
}
