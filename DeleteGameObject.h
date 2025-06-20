#pragma once
#include "Action.h"
class DeleteGameObject : public Action
{
	CellPosition c;
public:
	DeleteGameObject(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObject();
};

