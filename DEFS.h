#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	COPY_CARD,		// copy card action
	CUT_CARD,		// cut card action
	PASTE_CARD,     // paste already existed item
	EDIT_CARD,		//edit card
	DELETE_GAME_OBJECT, // delete game object
	SAVE_GRID,		//save the grid
	OPEN_GRID,		//open existing grid
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	INPUT_DICE_VALUE, // input dice value
	NEW_GAME, // new game
	TO_DESIGN_MODE,	// Go to Design Mode
	EXIT_GAME,
	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif