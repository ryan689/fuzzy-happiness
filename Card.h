#ifndef CARD_H
#define	CARD_H

#include <iostream>
using namespace std;

class Card
{
public:
    string name;
    float cost; // add .5 to cost in coins if potion cost
    int rank; // lower number for rank means it is higher ranked.
    int uses;
    float cards;
    float actions;
    float buys;
    float coins;
    string set;
    string type;
    float trasher;
    bool setup; // special setup required?
    bool blacklisted;
    bool whitelisted;
    bool whitelisted_helper; // dumb
    int speed; // how fast the card is
    bool bane; // true if a bane card
    bool previous; // true if card was used in the previous kingdom
    
    void print()
    {
        cout << "Name: " << name << "\n";
        cout << "\tCost: " << cost << 
                "\n\tRank: ";
        if (rank > 0)
            cout << "+";
        cout << rank << "\n\tUses: " << uses <<
                "\n\t+Cards: " << cards << "\n\t+Actions " << actions <<
                "\n\t+Buys: " << buys << "\n\t+Coins " << coins <<
                "\n\tSet: " << set << endl;
    }
};

#endif	/* CARD_H */