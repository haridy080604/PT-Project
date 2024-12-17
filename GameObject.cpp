#include "GameObject.h"

GameObject::GameObject(const CellPosition& pos)
{
	position = pos; // Sets Position
}

GameObject::GameObject()
{
	position = CellPosition::GetCellPositionFromNum(1); // Sets Position
}

bool GameObject::IsOverlapping(GameObject* newObj) const
{
	return false;
}

CellPosition GameObject::GetPosition() const
{
	return position;
}


GameObject::~GameObject()
{
}
