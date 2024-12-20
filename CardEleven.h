#ifndef CARD_Eleven_H
#define CARD_Eleven_H

#include "Card.h"
#include "Player.h"
#include "Grid.h"

class CardEleven : public Card
{
private:
    static Player* pOwner;     // Owner of all Card Eleven stations
    static int CardPrice;      // Price of the station
    static int Fees;           // Fees to be paid when other players land
    //static bool PrintOnce;     // Ensure price is printed only once
    //static bool ReadOnce;      // Ensure price is read only once

public:
    CardEleven(const CellPosition& pos);  // Parameterized constructor
    CardEleven();                         // Default constructor

    // Override virtual functions from Card base class
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);


    // Additional methods
    /*static void EndPrint();
    static void EndRead();*/
};

#endif // CARD_Eleven_H
