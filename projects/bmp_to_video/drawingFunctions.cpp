#include "drawingFunctions.h"
#include <cmath>
void drawRect(BITMAP& bit,int x, int y, int w, int h, Color col)
{
    for(int i{};i<w;++i)
    {
        bit.setPixel(x+i,y,col);
        bit.setPixel(x+i,y+h-1,col);
    }
    for(int i{1};i<h;++i)
    {
        bit.setPixel(x,y+i,col);
        bit.setPixel(x+w-1,y+i,col);
    }
}
void fillRect(BITMAP& bit,int x, int y, int w, int h, Color col)
{
    for(int i{};i<w;++i)
    {
        for(int j{};j<h;++j)
        {
            bit.setPixel(x+i,y+j,col);
        }
    }
}

// https://enchantia.com/graphapp/doc/tech/ellipses.html

#define incx() x++, dxt += d2xt, t += dxt
#define incy() y--, dyt += d2yt, t += dyt
void drawEllipse(BITMAP& bit,int xc, int yc, int a, int b, Color col)
{
    int x = 0, y = b;
    long a2 = (long)a*a, b2 = (long)b*b;
    long crit1 = -(a2/4 + a%2 + b2);
    long crit2 = -(b2/4 + b%2 + a2);
    long crit3 = -(b2/4 + b%2);
    long t = -a2*y; /* e(x+1/2,y-1/2) - (a^2+b^2)/4 */
    long dxt = 2*b2*x, dyt = -2*a2*y;
    long d2xt = 2*b2, d2yt = 2*a2;

    while (y>=0 && x<=a) 
    {
        bit.setPixel(xc+x, yc+y,col);
        if (x!=0 || y!=0)
            bit.setPixel(xc-x, yc-y,col);
        if (x!=0 && y!=0) 
        {
            bit.setPixel(xc+x, yc-y,col);
            bit.setPixel(xc-x, yc+y,col);
        }
        if (t + b2*x <= crit1 ||   /* e(x+1,y-1/2) <= 0 */
            t + a2*y <= crit3)     /* e(x+1/2,y) <= 0 */
            incx();
        else if (t - a2*y > crit2) /* e(x+1/2,y-1) > 0 */
            incy();
        else 
        {
            incx();
            incy();
        }
    }
}

void row(BITMAP& bit, int x,int y, int w, Color col)
{
    for(int i{};i<w;++i)
    {
        bit.setPixel(x+i,y,col);
    }
}

void fillEllipse(BITMAP& bit,int xc, int yc, int a, int b, Color col)
{
    int x = 0, y = b;
    unsigned int width = 1;
    long a2 = (long)a*a, b2 = (long)b*b;
    long crit1 = -(a2/4 + a%2 + b2);
    long crit2 = -(b2/4 + b%2 + a2);
    long crit3 = -(b2/4 + b%2);
    long t = -a2*y; /* e(x+1/2,y-1/2) - (a^2+b^2)/4 */
    long dxt = 2*b2*x, dyt = -2*a2*y;
    long d2xt = 2*b2, d2yt = 2*a2;

    while (y>=0 && x<=a) {
        if (t + b2*x <= crit1 ||     /* e(x+1,y-1/2) <= 0 */
            t + a2*y <= crit3) {     /* e(x+1/2,y) <= 0 */
            incx();
            width += 2;
        }
        else if (t - a2*y > crit2) { /* e(x+1/2,y-1) > 0 */
            row(bit,xc-x, yc-y, width,col);
            if (y!=0)
                row(bit,xc-x, yc+y, width,col);
            incy();
        }
        else {
            row(bit,xc-x, yc-y, width,col);
            if (y!=0)
                row(bit,xc-x, yc+y, width,col);
            incx();
            incy();
            width += 2;
        }
    }
    if (b == 0)
        row(bit,xc-a, yc, 2*a+1,col);
}

void __fillEllipse(BITMAP& bit,int xc, int yc, int a, int b, Color col)
{
    int x = 0, y = b;
    int rx = x, ry = y;
    unsigned int width = 1;
    unsigned int height = 1;
    long a2 = (long)a*a, b2 = (long)b*b;
    long crit1 = -(a2/4 + a%2 + b2);
    long crit2 = -(b2/4 + b%2 + a2);
    long crit3 = -(b2/4 + b%2);
    long t = -a2*y; /* e(x+1/2,y-1/2) - (a^2+b^2)/4 */
    long dxt = 2*b2*x, dyt = -2*a2*y;
    long d2xt = 2*b2, d2yt = 2*a2;

    if (b == 0) {
        fillRect(bit,xc-a, yc, 2*a+1, 1,col);
        return;
    }

    while (y>=0 && x<=a) 
    {
        if (t + b2*x <= crit1 ||     /* e(x+1,y-1/2) <= 0 */
            t + a2*y <= crit3)       /* e(x+1/2,y) <= 0 */
        {     
            if (height == 1)
                ; /* draw nothing */
            else if (ry*2+1 > (height-1)*2) 
            {
                fillRect(bit,xc-rx, yc-ry, width, height-1,col);
                fillRect(bit,xc-rx, yc+ry+1, width, 1-height,col);
                ry -= height-1;
                height = 1;
            }
            else 
            {
                fillRect(bit,xc-rx, yc-ry, width, ry*2+1,col);
                ry -= ry;
                height = 1;
            }
            incx();
            rx++;
            width += 2;
        }
        else if (t - a2*y > crit2) /* e(x+1/2,y-1) > 0 */
        {
            incy();
            height++;
        }
        else {
            if (ry*2+1 > height*2) 
            {
                fillRect(bit,xc-rx, yc-ry, width, height,col);
                fillRect(bit,xc-rx, yc+ry+1, width, -height,col);
            }
            else 
            {
                fillRect(bit,xc-rx, yc-ry, width, ry*2+1,col);
            }
            incx();
            incy();
            rx++;
            width += 2;
            ry -= height;
            height = 1;
        }
    }

    if (ry > height) 
    {
        fillRect(bit,xc-rx, yc-ry, width, height,col);
        fillRect(bit,xc-rx, yc+ry+1, width, -height,col);
    }
    else 
    {
        fillRect(bit,xc-rx, yc-ry, width, ry*2+1,col);
    }
}


namespace localSpaceForLineDrawing1
{
void plot(int x,int y,float c, BITMAP& bit, Color col)
{
    bit.addPixel(x,y,c,col);
}
void swap(int& a,int& b)
{
    a+=b;
    b=a-b;
    a-=b;
}
int ipart(float x){return floor(x);}
int round(float x) {return ipart(x + 0.5);}

// fractional part of x
float fpart(float x) {return x - ipart(x);}
float rfpart(float x) {return 1 - fpart(x);}

void drwLn(BITMAP& bit,int x0, int y0, int x1, int y1, Color col)
{
    bool steep{abs(y1 - y0) > abs(x1 - x0)};
    
    if (steep) 
    {
        swap(x0, y0);
        swap(x1, y1);
    }
    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }
    
    int dx = x1 - x0;
    int dy = y1 - y0;
    float gradient{};
    if (dx == 0)
        gradient = 1.0;
    else
        gradient = (float)dy / (float)dx;

    // handle first endpoint
    int xend = round(x0);
    float yend = y0 + gradient * (xend - x0);
    float xgap = rfpart(x0 + 0.5);
    int xpxl1 = xend; // this will be used in the main loop
    int ypxl1 = ipart(yend);
    if (steep)
    {
        plot(ypxl1,   xpxl1, rfpart(yend) * xgap, bit, col);
        plot(ypxl1+1, xpxl1,  fpart(yend) * xgap, bit, col);
    }
    else
    {
        plot(xpxl1, ypxl1  , rfpart(yend) * xgap, bit, col);
        plot(xpxl1, ypxl1+1,  fpart(yend) * xgap, bit, col);
    }
    float intery = yend + gradient; // first y-intersection for the main loop
    
    // handle second endpoint
    xend = round(x1);
    yend = y1 + gradient * (xend - x1);
    xgap = fpart(x1 + 0.5);
    float xpxl2 = xend; //this will be used in the main loop
    float ypxl2 = ipart(yend);
    if (steep)
    {
        plot(ypxl2  , xpxl2, rfpart(yend) * xgap, bit, col);
        plot(ypxl2+1, xpxl2,  fpart(yend) * xgap, bit, col);
    }
    else
    {
        plot(xpxl2, ypxl2,  rfpart(yend) * xgap, bit, col);
        plot(xpxl2, ypxl2+1, fpart(yend) * xgap, bit, col);
    }
    
    // main loop
    if (steep)
    {
        for(int x{xpxl1 + 1};x<=xpxl2 - 1;x++)
        {  
            plot(ipart(intery)  , x, rfpart(intery), bit, col);
            plot(ipart(intery)+1, x,  fpart(intery), bit, col);
            intery = intery + gradient;
        }
           
    }
    else
    {
        for(int x{xpxl1 + 1};x<=xpxl2 - 1;x++)
        {
            plot(x, ipart(intery),  rfpart(intery), bit, col);
            plot(x, ipart(intery)+1, fpart(intery), bit, col);
            intery = intery + gradient;
        }
    }
}
}

void drawLine(BITMAP& bit,int x1, int y1, int x2, int y2, Color col)
{
    localSpaceForLineDrawing1::drwLn(bit,x1,y1,x2,y2,col);
}