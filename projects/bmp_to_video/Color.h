#pragma once

class Color
{
private:
    unsigned char r{};
    unsigned char g{};
    unsigned char b{};
public:
    Color();
    Color(int r,int g, int b);
    unsigned char getR();
    unsigned char getG();
    unsigned char getB();
    void setR(int);
    void setG(int);
    void setB(int);
};