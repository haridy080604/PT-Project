#pragma once
#include "Action.h"
class CopyCard :
    public Action
{
	CellPosition c;
public:
	CopyCard(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCard();
};

