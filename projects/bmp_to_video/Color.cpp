#include "Color.h"

Color::Color(){};

Color::Color(int _r,int _g, int _b)
{
    setR(_r);
    setG(_g);
    setB(_b);
};

unsigned char Color::getR(){return r;}
unsigned char Color::getG(){return g;}
unsigned char Color::getB(){return b;}

void Color::setR(int newR)
{
    if(newR>=0&&newR<=255)
        r=static_cast<unsigned char>(newR);
    else if(newR<0)
        r=static_cast<unsigned char>(0);
    else//if(newr>255)
        r=static_cast<unsigned char>(255);
}
void Color::setG(int newG)
{
    if(newG>=0&&newG<=255)
        g=static_cast<unsigned char>(newG);
    else if(newG<0)
        g=static_cast<unsigned char>(0);
    else//if(newr>255)
        g=static_cast<unsigned char>(255);
}
void Color::setB(int newB)
{
    if(newB>=0&&newB<=255)
        b=static_cast<unsigned char>(newB);
    else if(newB<0)
        b=static_cast<unsigned char>(0);
    else//if(newr>255)
        b=static_cast<unsigned char>(255);
}

//int Color::getBGR()
//{
//    return ((b<<16)|(g<<8)|(r));
//}