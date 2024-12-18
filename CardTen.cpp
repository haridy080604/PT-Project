#include "CardTen.h"

// Static member initializations
Player* CardTen::pOwner = nullptr;
int CardTen::CardPrice = -1;
int CardTen::Fees = -1;
bool CardTen::PrintOnce = false;
bool CardTen::ReadOnce = false;

// Constructors
CardTen::CardTen(const CellPosition& pos) : Card(pos) { cardNumber = 10; }
CardTen::CardTen() : Card() {}




// Read Card Parameters
void CardTen::ReadCardParameters(Grid* pGrid) {
    if (CardPrice == -1 && Fees == -1) {
        // Get Card Price
        pGrid->GetOutput()->PrintMessage("Enter Price for Card Ten:");
        CardPrice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

        if (CardPrice < 0) {
            pGrid->PrintErrorMessage("Invalid Price. Click to continue.");
            CardPrice = -1;
            return;
        }

        // Get Fees
        pGrid->GetOutput()->PrintMessage("Enter Fees for Card Ten:");
        Fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

        if (Fees < 0) {
            pGrid->PrintErrorMessage("Invalid Fees. Click to continue.");
            CardPrice = -1;
            Fees = -1;
            return;
        }

        pGrid->GetOutput()->ClearStatusBar();
    }
}

// Apply Card Logic
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
    if (!pOwner) // If there's no owner yet
    {
        pGrid->GetOutput()->PrintMessage("Do you want to buy all cards with this number for " + std::to_string(CardPrice) + "? Enter 1 for Yes, 0 for No:");
        int decision = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
        pGrid->GetOutput()->ClearStatusBar();

        if (decision != 1 || pPlayer->GetWallet() < CardPrice)
        {
            pGrid->PrintErrorMessage("Insufficient funds or declined. Click to continue...");
            return;
        }

        // Deduct price from player's wallet
        pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);

        return;
    }

    if (pPlayer != pOwner && pOwner != nullptr) // If owned by another player
    {
        if (pPlayer->GetWallet() >= Fees)
        {
            pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
            pOwner->SetWallet(pOwner->GetWallet() + Fees);
        }// Deduct fees from player's wallet
        else
        {
            pOwner->SetWallet(pOwner->GetWallet() + pPlayer->GetWallet());
            pPlayer->SetWallet(0); // Deduct fees from player's wallet
        }
    }
}

// Additional Static Methods
void CardTen::EndPrint() {
    // Reset print flag
    PrintOnce = false;
}

void CardTen::EndRead() {
    // Reset read flag
    ReadOnce = false;
}
