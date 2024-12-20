#pragma once
#include "Action.h"
class InputDiceValueAction :
    public Action
{
    int diceNumber;
public:
    InputDiceValueAction(ApplicationManager* pApp);
    void ReadActionParameters();
    void Execute();
    ~InputDiceValueAction();
};
