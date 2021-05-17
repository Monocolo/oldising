#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
private:

public:
    int _id;
    string _name;
    int _inv;
    int paraphrase(int tag);
};


class CardHeap
{
private:
    int cardnum;
    Card drawcardheap[80];

public:
    int topcard;
    void init(int mod = 1);
    void shuffle();
    Card draw();
};



#endif // CARD_H
