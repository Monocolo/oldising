#include <string>
#include <iostream>
#include <stdio.h>
#include "page.h"
#include "story.h"
#include "buffer.h"
using namespace std;

Page::Page()
{
    _id = 0;
    _name = "home_page";

}

void Page::show(HUD *handle)
{
    char **screen = new char*[SCREEN_HEIGHT];
    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        screen[i] = new char[SCREEN_WIDTH];
    }
    for(int i = 0; i < SCREEN_HEIGHT; i++ ) {
        for(int j = 0; j < SCREEN_WIDTH; j++ ) {
            screen[i][j]=' ';
        }
    }

    switch(_id) {
    case HOME_PAGE:
        string str[SCREEN_HEIGHT];
        str[5] = "    1:start";
        str[6] = "    2:load";
        str[7] = "    3:exit";
        for(int i = 0; i < SCREEN_HEIGHT; i++ ) {
            for(int j = 0; j < str[i].size(); j++ ) {
                screen[i][j] = str[i][j];
            }
        }

        for(int i = 0; i < SCREEN_HEIGHT; i++ ) {
            screen[i][0] = '*';
            screen[i][SCREEN_WIDTH-1] = '*';
        }
        for(int j = 0; j < SCREEN_WIDTH; j++ ) {
            screen[0][j] = '*';
            screen[SCREEN_HEIGHT-1][j] = '*';
        }
        break;

    }


    //show
    buffer_show(handle,screen,SCREEN_HEIGHT,SCREEN_WIDTH);


//    for(int i = 0; i < SCREEN_HEIGHT; i++ ) {
//        for(int j = 0; j < SCREEN_WIDTH; j+=2 ) {
//            char stmp[3];
//            stmp[0]=screen[i][j];
//            stmp[1]=screen[i][j+1];
//            stmp[2]='\0';
//            cout << stmp;
//        }
//        cout<<endl;
//    }
}
