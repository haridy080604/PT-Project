#include "Player.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum),MoveAgain(false)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->Freeze = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetJustRolledDiceNum()
{
	return justRolledDiceNum;
}

void Player::SetTurnCount(int new_turn_count)
{
	turnCount = new_turn_count;

}

void Player::setFreeze(bool a)
{
	Freeze = a;
}

void Player::setMoveAgain(bool a)
{
	MoveAgain = a;
}

bool Player::GetMoveAgain()
{
	return MoveAgain;
}

int Player::getPlayerNumber()
{
	return playerNum;
}

bool Player::GetFreeze()
{
	return Freeze;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	
		turnCount++;
		if (turnCount == 3)
		{
			turnCount = 0;
			SetWallet(GetWallet() + 10);
		}
		else

			justRolledDiceNum = diceNumber;

		CellPosition& pos = pCell->GetCellPosition();
		pos.AddCellNum(diceNumber);


		pGrid->UpdatePlayerCell(this, pos);


		if (pCell->GetGameObject() != NULL)
		{

			pCell->GetGameObject()->Apply(pGrid, this);

		}
		if (pCell->GetCellPosition().GetCellNum() == 99)
		{
			pGrid->SetEndGame(true);
		}







		///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) to implement this function ==


		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

		// 3- Set the justRolledDiceNum with the passed diceNumber

		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"

		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		// 6- Apply() the game object of the reached cell (if any)

		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

	

}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
