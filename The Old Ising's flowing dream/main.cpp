#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "page.h"
#include "story.h"
#include "card.h"
#include "player.h"
#include "buffer.h"
using namespace std;
/*
Menu
    page_show
        background_show
        options_show
    seletc_option
    if start
        goto Flow
    else load
        goto S/L
    else exit
        goto Exit

Flow
    card_draw_page
    card_paraphrase
    page_show
        background_show
        options_show(0)
    player_choose_option(0)
    page_active
        player_action
    card_draw_award
    page_update
    table_update
    player_updat

S/L

Exit

*/
struct TableLog
{
    int page_id;


} table;

int main()
{
    table.page_id = HOME_PAGE;

    CardHeap cardheap;
    cardheap.init(0);
    cardheap.shuffle();

    Page page;

    Card card;

    Player player;

    HUD handle;
    handle_init(&handle);

    string sentence;

    while(1) {
        //card_draw
        if(cardheap.topcard > 0) {
            card = cardheap.draw();
        }
        else {
            cardheap.shuffle();
            card = cardheap.draw();
        }
        //player_action
        player.handcard = card.paraphrase(CARD_WAY);
        player.action();

        //page_show
        page.show(&handle);

        //player_choose
        player.choose(page._id);


        getchar();
//        system("cls");
    }



    return 0;
}
