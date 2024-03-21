#include "BITMAP.h"
#include "Color.h"
#include <fstream>
#include <iostream>
#include <algorithm>

BITMAP::BITMAP(int w, int h)
{
    _width = w;
    _height = h;
    padding = (4 - (_width * bpp) % 4 ) % 4;
    dataArray = std::vector<Color>();
    dataArray.resize(_width*_height,Color(0,0,0));
}

BITMAP::~BITMAP()
{
    
}

void BITMAP::saveImage(std::string path)
{
    padding = (4 - (_width * bpp) % 4 ) % 4;
    int dsz = _width*_height*bpp + padding * _height;//datasize
    int flsz = 14 + 40 + dsz;//file size
    //header = 14 bytes
    unsigned char signature[2] = {'B','M'};//file signature
    unsigned char fileSize[4]={static_cast<unsigned char>(flsz),static_cast<unsigned char>(flsz>>8),static_cast<unsigned char>(flsz>>16),static_cast<unsigned char>(flsz>>24)};
    unsigned char reserved[4] = {0x0,0x0,0x0,0x0};//reserved & unused
    unsigned char dataOffset[4] = {0x36,0x0,0x0,0x0};//data starts at 14 + 40 byte
    //infoHeader = 40 bytes
    unsigned char size[4] = {0x28,0x0,0x0,0x0}; //40 bytes
    unsigned char wdth[4]={static_cast<unsigned char>(_width),static_cast<unsigned char>(_width>>8),static_cast<unsigned char>(_width>>16),static_cast<unsigned char>(_width>>24)};
    unsigned char hght[4]={static_cast<unsigned char>(_height),static_cast<unsigned char>(_height>>8),static_cast<unsigned char>(_height>>16),static_cast<unsigned char>(_height>>24)};
    unsigned char planes[2] = {0x1,0x0};
    unsigned char bitsPerPixel[2] = {0x18,0x0};//24 bites per pixel
    unsigned char compression[4] = {0x0,0x0,0x0,0x0};//no compression
    unsigned char imageSize[4]={static_cast<unsigned char>(dsz),static_cast<unsigned char>(dsz>>8),static_cast<unsigned char>(dsz>>16),static_cast<unsigned char>(dsz>>24)};//pure data size (with paddings)
    unsigned char xPixelPerM[4] = {0x1,0x0,0x0,0x0};
    unsigned char yPixelPerM[4] = {0x1,0x0,0x0,0x0};
    unsigned char colorsUsed[4] = {0x0,0x0,0x0,0x0};//there will be no color table
    unsigned char importantColors[4]={0x0,0x0,0x0,0x0};//all colors are important
    //data
    unsigned char* data=new unsigned char[dsz];
    int t{};//index for data bytes
    for(int j{};j<_height;++j)
    {
        for(int i{};i<_width;++i)
        {
            //int bgr = dataArray[i+j*_width].getBGR();
            data[t++] = dataArray[i+j*_width].getB();//static_cast<unsigned char>((bgr>>16)&0xff);
            data[t++] = dataArray[i+j*_width].getG();//static_cast<unsigned char>((bgr>>8)&0xff);
            data[t++] = dataArray[i+j*_width].getR();//static_cast<unsigned char>((bgr)&0xff);
        }
        //add padding
        for(int i{};i<padding;++i)
            data[t++]=0;
    }

    //writing file down
    std::ofstream f;
    f.open(path,std::ios::out | std::ios::binary);
    if(!f.is_open())
    {
        std::cout<<"the file failed to open"<<std::endl;
        return;
    }
    //header
    f.write(reinterpret_cast<char*>(signature),sizeof(signature));
    f.write(reinterpret_cast<char*>(fileSize),sizeof(fileSize));
    f.write(reinterpret_cast<char*>(reserved),sizeof(reserved));
    f.write(reinterpret_cast<char*>(dataOffset),sizeof(dataOffset));
    //infoHeader
    f.write(reinterpret_cast<char*>(size),sizeof(size));
    f.write(reinterpret_cast<char*>(wdth),sizeof(wdth));
    f.write(reinterpret_cast<char*>(hght),sizeof(hght));
    f.write(reinterpret_cast<char*>(planes),sizeof(planes));
    f.write(reinterpret_cast<char*>(bitsPerPixel),sizeof(bitsPerPixel));
    f.write(reinterpret_cast<char*>(compression),sizeof(compression));
    f.write(reinterpret_cast<char*>(imageSize),sizeof(imageSize));
    f.write(reinterpret_cast<char*>(xPixelPerM),sizeof(xPixelPerM));
    f.write(reinterpret_cast<char*>(yPixelPerM),sizeof(yPixelPerM));
    f.write(reinterpret_cast<char*>(colorsUsed),sizeof(colorsUsed));
    f.write(reinterpret_cast<char*>(importantColors),sizeof(importantColors));
    //data
    f.write(reinterpret_cast<char*>(data),dsz);
    f.close();
}

void BITMAP::setPixel(int x, int y, Color col)
{
    if(x>=0&&x<_width&&y>=0&&y<_height)
        dataArray[(_height-y-1)*_width+x]=col;
    //else
    //    dataArray[(_height-(y%_height)-1)*_width+(x%_width)]=col;

}

void BITMAP::addPixel(int x, int y, float k, Color col)
{   //0<=k<=1
    //k=1 -> col
    //k=0 -> pixelCurrentColor
    if(x>=0&&x<_width&&y>=0&&y<_height)
    {
        int curR{dataArray[(_height-y-1)*_width+x].getR()};
        int curG{dataArray[(_height-y-1)*_width+x].getG()};
        int curB{dataArray[(_height-y-1)*_width+x].getB()};
        int R{col.getR()};
        int G{col.getG()};
        int B{col.getB()};
        
        dataArray[(_height-y-1)*_width+x]=Color(abs(static_cast<int>(R*k-curR*(1-k))),
                                                abs(static_cast<int>(G*k-curG*(1-k))),
                                                abs(static_cast<int>(B*k-curB*(1-k))));
    }
}

Color BITMAP::getPixel(int x,int y)
{
    if(x>=0&&x<_width&&y>=0&&y<_height)
        return dataArray[x+(_height-y-1)*_width];
    else
        return Color(0,0,0);
        //return dataArray[x%_width+(_height-y%_height-1)*_width];
}

void BITMAP::fillColor(Color col)
{
    std::fill(dataArray.begin(),dataArray.end(),col);
    //for(int i{};i<_height;++i)
    //{
    //    for(int j{};j<_width;++j)
    //    {
    //        dataArray[j+i*_width] = col;
    //    }
    //}
    //dataArray.resize(_width*_height,col);
}

