#include "CellPosition.h"
#include "UI_Info.h"


CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}


	return false;
}

bool CellPosition::SetHCell(int h)
{
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}



	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (vCell >= 0 && vCell <= 10 && hCell >= 0 && hCell <= 10)
	{

		return true;
	}

	else

		return false;







}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	int cellnumber = (cellPosition.hCell + 1) + (8 - cellPosition.vCell) * 11;



	return cellnumber; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	CellPosition position;


	if (cellNum >= 1 && cellNum <= 99) {
		if (((cellNum % 11) - 1) == -1)
			position.hCell = 10;
		else
			position.hCell = (cellNum % 11) - 1;
		position.vCell = 8 + ((position.hCell + 1 - cellNum) / 11);

	}
	return position;

}






void CellPosition::AddCellNum(int addedNum)
{

	int newCellNum = GetCellNum() + addedNum;

	if (newCellNum >= 1 && newCellNum <= 99) {
		if (((newCellNum % 11) - 1) == -1)
			hCell = 10;
		else
			hCell = (newCellNum % 11) - 1;
		vCell = (newCellNum - (hCell + 1)) / 11;
	}
}

