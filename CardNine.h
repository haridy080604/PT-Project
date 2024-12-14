#pragma once
#include "Card.h"

class CardNine : public Card
{
private:
    CellPosition moveToCell; // The cell to move the player to

public:
    // Constructor
    CardNine(const CellPosition& pos);
    CardNine();
    // Virtual Methods
    virtual void ReadCardParameters(Grid* pGrid); // Reads the target cell to move the player to
    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the card's effect

    // Save and Load
    virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;
    virtual void Read(ifstream& InFile);

    // Destructor
    virtual ~CardNine();
};
