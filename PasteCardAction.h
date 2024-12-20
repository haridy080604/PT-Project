#pragma once
#include "Action.h"
class PasteCardAction :
    public Action
{
    CellPosition c;
public:
    PasteCardAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~PasteCardAction();
};

