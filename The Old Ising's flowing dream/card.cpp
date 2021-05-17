#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "story.h"
#include "card.h"
using namespace std;

void CardHeap::init(int mod)
{
    //mod=0 first init
    if( mod == 0) {
        srand((unsigned int)time(NULL));
        cardnum = 78 + rand()%3;
    }
    topcard = cardnum-1;

    drawcardheap[0]._id = 0;
    drawcardheap[0]._name = "The Fool, 0";
    drawcardheap[0]._inv = 0;

    drawcardheap[1]._id = 1;
    drawcardheap[1]._name = "The Magician,I";
    drawcardheap[1]._inv = 0;

    drawcardheap[2]._id = 2;
    drawcardheap[2]._name = "The High Priestess,II";
    drawcardheap[2]._inv = 0;

    drawcardheap[3]._id = 3;
    drawcardheap[3]._name = "The Empress,III";
    drawcardheap[3]._inv = 0;

    drawcardheap[4]._id = 4;
    drawcardheap[4]._name = "The Emperor,IV";
    drawcardheap[4]._inv = 0;

    drawcardheap[5]._id = 5;
    drawcardheap[5]._name = "The Hierophant,V";
    drawcardheap[5]._inv = 0;

    drawcardheap[6]._id = 6;
    drawcardheap[6]._name = "The Lovers,VI";
    drawcardheap[6]._inv = 0;

    drawcardheap[7]._id = 7;
    drawcardheap[7]._name = "The Chariot,VII";
    drawcardheap[7]._inv = 0;

    drawcardheap[8]._id = 8;
    drawcardheap[8]._name = "Strength,VIII";
    drawcardheap[8]._inv = 0;

    drawcardheap[9]._id = 9;
    drawcardheap[9]._name = "The Hermit,IX";
    drawcardheap[9]._inv = 0;

    drawcardheap[10]._id = 10;
    drawcardheap[10]._name = "The Wheel of Fortune,X";
    drawcardheap[10]._inv = 0;

    drawcardheap[11]._id = 11;
    drawcardheap[11]._name = "Justice,XI";
    drawcardheap[11]._inv = 0;

    drawcardheap[12]._id = 12;
    drawcardheap[12]._name = "The Hanged Man,XII";
    drawcardheap[12]._inv = 0;

    drawcardheap[13]._id = 13;
    drawcardheap[13]._name = "Death,XIII";
    drawcardheap[13]._inv = 0;

    drawcardheap[14]._id = 14;
    drawcardheap[14]._name = "Temperance,XIV";
    drawcardheap[14]._inv = 0;

    drawcardheap[15]._id = 15;
    drawcardheap[15]._name = "The Devil,XV";
    drawcardheap[15]._inv = 0;

    drawcardheap[16]._id = 16;
    drawcardheap[16]._name = "The Tower,XVI";
    drawcardheap[16]._inv = 0;

    drawcardheap[17]._id = 17;
    drawcardheap[17]._name = "The Star,XVII";
    drawcardheap[17]._inv = 0;

    drawcardheap[18]._id = 18;
    drawcardheap[18]._name = "The Moon,XVIII";
    drawcardheap[18]._inv = 0;

    drawcardheap[19]._id = 19;
    drawcardheap[19]._name = "The Sun,XIX";
    drawcardheap[19]._inv = 0;

    drawcardheap[20]._id = 20;
    drawcardheap[20]._name = "Judgement,XX";
    drawcardheap[20]._inv = 0;

    drawcardheap[21]._id = 21;
    drawcardheap[21]._name = "The World,XXI";
    drawcardheap[21]._inv = 0;

    drawcardheap[22]._id = 22;
    drawcardheap[22]._name = "ace of wands";
    drawcardheap[22]._inv = 0;

    drawcardheap[23]._id = 23;
    drawcardheap[23]._name = "II of wands";
    drawcardheap[23]._inv = 0;

    drawcardheap[24]._id = 24;
    drawcardheap[24]._name = "III of wands";
    drawcardheap[24]._inv = 0;

    drawcardheap[25]._id = 25;
    drawcardheap[25]._name = "IV of wands";
    drawcardheap[25]._inv = 0;

    drawcardheap[26]._id = 26;
    drawcardheap[26]._name = "V of wands";
    drawcardheap[26]._inv = 0;

    drawcardheap[27]._id = 27;
    drawcardheap[27]._name = "VI of wands";
    drawcardheap[27]._inv = 0;

    drawcardheap[28]._id = 28;
    drawcardheap[28]._name = "VII of wands";
    drawcardheap[28]._inv = 0;

    drawcardheap[29]._id = 29;
    drawcardheap[29]._name = "VIII of wands";
    drawcardheap[29]._inv = 0;

    drawcardheap[30]._id = 30;
    drawcardheap[30]._name = "IX of wands";
    drawcardheap[30]._inv = 0;

    drawcardheap[31]._id = 31;
    drawcardheap[31]._name = "X of wands";
    drawcardheap[31]._inv = 0;

    drawcardheap[32]._id = 32;
    drawcardheap[32]._name = "Page of wands";
    drawcardheap[32]._inv = 0;

    drawcardheap[33]._id = 33;
    drawcardheap[33]._name = "Knight of wands";
    drawcardheap[33]._inv = 0;

    drawcardheap[34]._id = 34;
    drawcardheap[34]._name = "Queen of wands";
    drawcardheap[34]._inv = 0;

    drawcardheap[35]._id = 35;
    drawcardheap[35]._name = "King of wands";
    drawcardheap[35]._inv = 0;

    drawcardheap[36]._id = 36;
    drawcardheap[36]._name = "ace of swords";
    drawcardheap[36]._inv = 0;

    drawcardheap[37]._id = 37;
    drawcardheap[37]._name = "II of swords";
    drawcardheap[37]._inv = 0;

    drawcardheap[38]._id = 38;
    drawcardheap[38]._name = "III of swords";
    drawcardheap[38]._inv = 0;

    drawcardheap[39]._id = 39;
    drawcardheap[39]._name = "IV of swords";
    drawcardheap[39]._inv = 0;

    drawcardheap[40]._id = 40;
    drawcardheap[40]._name = "V of swords";
    drawcardheap[40]._inv = 0;

    drawcardheap[41]._id = 41;
    drawcardheap[41]._name = "VI of swords";
    drawcardheap[41]._inv = 0;

    drawcardheap[42]._id = 42;
    drawcardheap[42]._name = "VII of swords";
    drawcardheap[42]._inv = 0;

    drawcardheap[43]._id = 43;
    drawcardheap[43]._name = "VIII of swords";
    drawcardheap[43]._inv = 0;

    drawcardheap[44]._id = 44;
    drawcardheap[44]._name = "IX of swords";
    drawcardheap[44]._inv = 0;

    drawcardheap[45]._id = 45;
    drawcardheap[45]._name = "X of swords";
    drawcardheap[45]._inv = 0;

    drawcardheap[46]._id = 46;
    drawcardheap[46]._name = "Page of swords";
    drawcardheap[46]._inv = 0;

    drawcardheap[47]._id = 47;
    drawcardheap[47]._name = "Knight of swords";
    drawcardheap[47]._inv = 0;

    drawcardheap[48]._id = 48;
    drawcardheap[48]._name = "Queen of swords";
    drawcardheap[48]._inv = 0;

    drawcardheap[49]._id = 49;
    drawcardheap[49]._name = "King of swords";
    drawcardheap[49]._inv = 0;

    drawcardheap[50]._id = 50;
    drawcardheap[50]._name = "ace of cpus";
    drawcardheap[50]._inv = 0;

    drawcardheap[51]._id = 51;
    drawcardheap[51]._name = "II of cpus";
    drawcardheap[51]._inv = 0;

    drawcardheap[52]._id = 52;
    drawcardheap[52]._name = "III of cpus";
    drawcardheap[52]._inv = 0;

    drawcardheap[53]._id = 53;
    drawcardheap[53]._name = "IV of cpus";
    drawcardheap[53]._inv = 0;

    drawcardheap[54]._id = 54;
    drawcardheap[54]._name = "V of cpus";
    drawcardheap[54]._inv = 0;

    drawcardheap[55]._id = 55;
    drawcardheap[55]._name = "VI of cpus";
    drawcardheap[55]._inv = 0;

    drawcardheap[56]._id = 56;
    drawcardheap[56]._name = "VII of cpus";
    drawcardheap[56]._inv = 0;

    drawcardheap[57]._id = 57;
    drawcardheap[57]._name = "VIII of cpus";
    drawcardheap[57]._inv = 0;

    drawcardheap[58]._id = 58;
    drawcardheap[58]._name = "IX of cpus";
    drawcardheap[58]._inv = 0;

    drawcardheap[59]._id = 59;
    drawcardheap[59]._name = "X of cpus";
    drawcardheap[59]._inv = 0;

    drawcardheap[60]._id = 60;
    drawcardheap[60]._name = "Page of cpus";
    drawcardheap[60]._inv = 0;

    drawcardheap[61]._id = 61;
    drawcardheap[61]._name = "Knight of cpus";
    drawcardheap[61]._inv = 0;

    drawcardheap[62]._id = 62;
    drawcardheap[62]._name = "Queen of cpus";
    drawcardheap[62]._inv = 0;

    drawcardheap[63]._id = 63;
    drawcardheap[63]._name = "King of cpus";
    drawcardheap[63]._inv = 0;

    drawcardheap[64]._id = 64;
    drawcardheap[64]._name = "ace of pentacles";
    drawcardheap[64]._inv = 0;

    drawcardheap[65]._id = 65;
    drawcardheap[65]._name = "II of pentacles";
    drawcardheap[65]._inv = 0;

    drawcardheap[66]._id = 66;
    drawcardheap[66]._name = "III of pentacles";
    drawcardheap[66]._inv = 0;

    drawcardheap[67]._id = 67;
    drawcardheap[67]._name = "IV of pentacles";
    drawcardheap[67]._inv = 0;

    drawcardheap[68]._id = 68;
    drawcardheap[68]._name = "V of pentacles";
    drawcardheap[68]._inv = 0;

    drawcardheap[69]._id = 69;
    drawcardheap[69]._name = "VI of pentacles";
    drawcardheap[69]._inv = 0;

    drawcardheap[70]._id = 70;
    drawcardheap[70]._name = "VII of pentacles";
    drawcardheap[70]._inv = 0;

    drawcardheap[71]._id = 71;
    drawcardheap[71]._name = "VIII of pentacles";
    drawcardheap[71]._inv = 0;

    drawcardheap[72]._id = 72;
    drawcardheap[72]._name = "IX of pentacles";
    drawcardheap[72]._inv = 0;

    drawcardheap[73]._id = 73;
    drawcardheap[73]._name = "X of pentacles";
    drawcardheap[73]._inv = 0;

    drawcardheap[74]._id = 74;
    drawcardheap[74]._name = "Page of pentacles";
    drawcardheap[74]._inv = 0;

    drawcardheap[75]._id = 75;
    drawcardheap[75]._name = "Knight of pentacles";
    drawcardheap[75]._inv = 0;

    drawcardheap[76]._id = 76;
    drawcardheap[76]._name = "Queen of pentacles";
    drawcardheap[76]._inv = 0;

    drawcardheap[77]._id = 77;
    drawcardheap[77]._name = "King of pentacles";
    drawcardheap[77]._inv = 0;

    drawcardheap[78]._id = 78;
    drawcardheap[78]._name = "Blank card";
    drawcardheap[78]._inv = 0;

    drawcardheap[79]._id = 79;
    drawcardheap[79]._name = "Spare card";
    drawcardheap[79]._inv = 0;
}

void CardHeap::shuffle()
{
    //Card drawcardheap[80];
    srand((unsigned int)time(NULL));

    topcard = cardnum-1;
    for(int i = cardnum; i > 0; i-- ) {
        int it1 = rand()%i;
        int it2 = cardnum-1;

        Card *cardtmp = new Card(drawcardheap[it2]);
        drawcardheap[it2] = drawcardheap[it1];
        drawcardheap[it1] = *cardtmp;
        delete cardtmp;
        cardtmp = NULL;
    }
}

Card CardHeap::draw()
{
    topcard--;
    return drawcardheap[topcard];
}


int Card::paraphrase(int tag)
{
    if(tag == CARD_WAY) {

    }

}



