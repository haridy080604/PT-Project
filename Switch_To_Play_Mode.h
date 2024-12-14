#ifndef Switch_To_Play_Mode_H
#define Switch_To_Play_Mode_H
#include"Action.h"
class Switch_To_Play_Mode :public Action 
{
	Switch_To_Play_Mode(ApplicationManager* App);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~Switch_To_Play_Mode();


};
#endif Switch_To_Play_Mode_H
