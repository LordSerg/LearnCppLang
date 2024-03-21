#include "Color.h"
#include "BITMAP.h"
#include "drawingFunctions.h"
#include <cmath>
#include <string>
#include <vector>
#include <iostream>


int main()
{
    //testing1
    /*
    BITMAP picture = BITMAP(256,256);
    picture.fillColor(Color(255,0,0));
    picture.setPixel(0,0,Color(32,64,128));
    picture.saveImage("H:\\shit1\\pictures\\test.bmp");
    */
    //testing2
    /*
    BITMAP picture = BITMAP(1280,1024);
    fillRect(picture,5,5,100,200,Color(0,255,0));
    drawRect(picture,5,5,100,200,Color(0,0,0));
    fillEllipse(picture,50,50,50,50,Color(0,0,255));
    drawEllipse(picture,50,50,50,50,Color(0,0,0));
    picture.saveImage("H:\\shit1\\pictures\\test7.bmp");
    */
    //make circle movement to video
    /*
    BITMAP picture = BITMAP(1280,1024);
    Color backColor(50,50,50);
    Color circleColor(125,125,125);
    int xc{50},yc{50},rx{50},ry{50},dx{15},dy{3};
    int frames{300};
    std::cout<<"creating files...";
    std::string path {"H:\\shit1\\pictures\\"};
    for(int i{};i<frames;i++)
    {
        //if(xc+rx+dx>picture.width())
        //    dx*=-1;
        //if(xc-rx+dx<0)
        //    dx*=-1;
        //if(yc+ry+dy>picture.height())
        //    dy*=-1;
        //if(yc-ry+dy<0)
        //    dy*=-1;
        xc+=dx;
        yc+=dy;
        //if(xc+rx>picture.width())
        //{
        //    xc=picture.width()-rx-((xc+rx)%picture.width());
        //    dx*=-1;
        //}
        //if(xc-rx<0)
        //{
        //    xc=rx+(rx-xc);
        //    dx*=-1;
        //}
        //if(yc>picture.height())
        //{
        //    yc=picture.height()-(yc%picture.height());
        //    dy*=-1;
        //}
        //if(yc<0)
        //{
        //    yc=-yc;
        //    dy*=-1;
        //}
        picture.fillColor(backColor);
        fillEllipse(picture,xc,yc,rx,ry,circleColor);
        
        picture.saveImage(path+std::to_string(i)+".bmp");
    }
    std::cout<<std::endl<<"files have been created successfully"<<std::endl;

    system("ffmpeg -i pictures\\%d.bmp -r 10 -c:v libx264 -preset slow -crf 21 output2.mp4");
    //ffmpeg -framerate 50 -i pictures\\%d.bmp -c:v libx264 -r 50 output.mp4
    std::cout<<"deleting...";
    std::string command{"del " + path};
    for(int i{};i<frames;++i)
    {
        std::string tmp{command+std::to_string(i)+".bmp"};
        system(reinterpret_cast<const char*>(tmp.c_str()));
    }
    std::cout<<std::endl<<"proces finished successfully"<<std::endl;
    */
    
    //draw line
    /*
    BITMAP bit = BITMAP(500,500);
    bit.fillColor(Color(255,0,0));
    drawLine(bit,256,176,354,50,Color(0,255,0));
    bit.saveImage("H:\\shit1\\pictures\\test8.bmp");
    */

    //draw rotating stick video
    BITMAP bit = BITMAP(500,500);
    Color backColor = Color(255,0,0);
    Color lineColor(0,255,0);
    double PI = 3.1415926535;
    bit.fillColor(backColor);

    int x0{250},y0{250},x1{},y1{},r{100};
    int frames{360};
    std::cout<<"creating files...";
    std::string path {"D:\\Languiges_C++\\projects\\bmp_to_video\\pictures\\"};
    for(int i{};i<frames;i++)
    {
        x1= x0+static_cast<int>(r*cos(i*PI/180.0));
        y1= y0+static_cast<int>(r*sin(i*PI/180.0));
        bit.fillColor(backColor);
        drawLine(bit,x0,y0,x1,y1,lineColor);
        bit.saveImage(path+std::to_string(i)+".bmp");
    }
    std::cout<<std::endl<<"files have been created successfully"<<std::endl;

    //system("ffmpeg -i pictures\\%d.bmp -r 10 -c:v libx264 -preset slow -crf 21 output2.mp4");
    system("ffmpeg -framerate 60 -i pictures\\%d.bmp -c:v libx264 -r 60 output.mp4");//looks nice
    //system("ffmpeg -framerate 60 -i pictures\\%d.bmp -c:v libx264 -r 10 output.mp4");//looks glitchy
    //system("ffmpeg -framerate 60 -i pictures\\%d.bmp -c:v libx264 -r 1 output.mp4");//gaps all frames
    //system("ffmpeg -framerate 1 -i pictures\\%d.bmp -c:v libx264 -r 60 output.mp4");//1 frame = 1 second
    //ffmpeg -framerate 50 -i pictures\\%d.bmp -c:v libx264 -r 50 output.mp4
    std::cout<<"deleting temporary files...";
    std::string command{"del " + path};
    for(int i{};i<frames;++i)
    {
        std::string tmp{command+std::to_string(i)+".bmp"};
        system(reinterpret_cast<const char*>(tmp.c_str()));
    }
    std::cout<<std::endl<<"proces finished successfully"<<std::endl; 

    //make fast-moving dot video
    
}