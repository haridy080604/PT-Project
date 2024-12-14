#ifndef CARD_Thirteen_H
#define CARD_Thirteen_H

#include "Card.h"
#include "Player.h"
#include "Grid.h"

class CardThirteen : public Card
{
private:
    static Player* pOwner;     // Owner of all Card Thirteen stations
    static int CardPrice;      // Price of the station
    static int Fees;           // Fees to be paid when other players land
    static bool PrintOnce;     // Ensure price is printed only once
    static bool ReadOnce;      // Ensure price is read only once

public:
    CardThirteen(const CellPosition& pos);  // Parameterized constructor
    CardThirteen();                         // Default constructor

    // Override virtual functions from Card base class
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    virtual void Save(ofstream& OutFile, GameObjectsType type) const;
    virtual void Read(ifstream& InFile);

    // Additional methods
    static void EndPrint();
    static void EndRead();
};

#endif // CARD_Thirteen_H