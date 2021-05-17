#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Backpack
{
private:

public:

};

class Player
{
private:

public:
    int handcard;
    Backpack pack;
    void choose(int pageid);
    void action();


};


#endif // PLAYER_H
