#pragma once
#include "Action.h"
#include "UI_Info.h"
class NewGameAction :
    public Action
{
public:
    NewGameAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~NewGameAction();
};

