#pragma once
#include "Color.h"
#include <string>
#include <vector>
//24bpp bitmap structure
class BITMAP
{
private:
    int _width;
    int _height;
    int bpp{3};//24 bit picture
    int padding;
    std::vector<Color> dataArray;
public:
    int width(){return _width;}
    int height(){return _height;}
    BITMAP(int width, int height);
    void saveImage(std::string path);
    void setPixel(int x,int y, Color col);
    void addPixel(int x,int y, float k, Color col);
    Color getPixel(int x,int y);
    void fillColor(Color col);
    ~BITMAP();
};
