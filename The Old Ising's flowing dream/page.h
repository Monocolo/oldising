#ifndef PAGE_H
#define PAGE_H

#include <string>
#include "buffer.h"
using namespace std;

class Page
{
private:
    string _name;
    int _line;



public:
    int _id;
    Page();
    void show(HUD *handle);

};

#endif // PAGE_H
