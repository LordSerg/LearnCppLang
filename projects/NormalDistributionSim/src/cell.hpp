#pragma once

//container, where particle eventually falls
class cell
{
    //height of the conteiner module
    static int height;
public:

    int getHeight();
    bool isInSlot();
};