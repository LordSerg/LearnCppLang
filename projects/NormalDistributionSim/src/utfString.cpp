#include "utfString.hpp"

int utf8_to_unicode(std::string utf8_code)
{
    unsigned utf8_size = utf8_code.length();
    int unicode = 0;

    for (unsigned p=0; p<utf8_size; ++p)
    {
        int bit_count = (p? 6: 8 - utf8_size - (utf8_size == 1? 0: 1)),
            shift = (p < utf8_size - 1? (6*(utf8_size - p - 1)): 0);

        for (int k=0; k<bit_count; ++k)
            unicode += ((utf8_code[p] & (1 << k)) << shift);
    }

    return unicode;
}


std::string unicode_to_utf8(int unicode)
{
    std::string s;

    if (unicode>=0 and unicode <= 0x7f)  // 7F(16) = 127(10)
    {
        s = static_cast<char>(unicode);

        return s;
    }
    else if (unicode <= 0x7ff)  // 7FF(16) = 2047(10)
    {
        unsigned char c1 = 192, c2 = 128;

        for (int k=0; k<11; ++k)
        {
            if (k < 6)
                c2 |= (unicode % 64) & (1 << k);
            else
                c1 |= (unicode >> 6) & (1 << (k - 6));
        }

        s = c1;
        s += c2;

        return s;
    }
    else if (unicode <= 0xffff)  // FFFF(16) = 65535(10)
    {
        unsigned char c1 = 224, c2 = 128, c3 = 128;

        for (int k=0; k<16; ++k)
        {
            if (k < 6)
                c3 |= (unicode % 64) & (1 << k);
            else if
                (k < 12) c2 |= (unicode >> 6) & (1 << (k - 6));
            else
                c1 |= (unicode >> 12) & (1 << (k - 12));
        }

        s = c1;
        s += c2;
        s += c3;

        return s;
    }
    else if (unicode <= 0x1fffff)  // 1FFFFF(16) = 2097151(10)
    {
        unsigned char c1 = 240, c2 = 128, c3 = 128, c4 = 128;

        for (int k=0; k<21; ++k)
        {
            if (k < 6)
                c4 |= (unicode % 64) & (1 << k);
            else if (k < 12)
                c3 |= (unicode >> 6) & (1 << (k - 6));
            else if (k < 18)
                c2 |= (unicode >> 12) & (1 << (k - 12));
            else
                c1 |= (unicode >> 18) & (1 << (k - 18));
        }

        s = c1;
        s += c2;
        s += c3;
        s += c4;

        return s;
    }
    else if (unicode <= 0x3ffffff)  // 3FFFFFF(16) = 67108863(10)
    {
        ;  // Actually, there are no 5-bytes unicodes
    }
    else if (unicode <= 0x7fffffff)  // 7FFFFFFF(16) = 2147483647(10)
    {
        ;  // Actually, there are no 6-bytes unicodes
    }
    else
        ;  // Incorrect unicode (< 0 or > 2147483647)

    return "";
}

void waitCursore(int i)
{//doing a snake waiting in console out of braille codes (0x2800 - 0x28FF) ~ (10240 - 10495)
    //erase preveous print
    std::cout<<"      \r";
    /*
    braile pattern:
    1 4
    2 5
    3 6
    7 8
    */
    //those of them, that we need are:
    /*
    1,14,4          = 0b00000001 0b00001001 0b00001000 
    2,25,5          = 0b00000010 0b00010010 0b00010000
    3,36,6          = 0b00000100 0b00100100 0b00100000
    7,78,8          = 0b01000000 0b11000000 0b10000000
    1245,2356,3678  = 0b00011011 0b00110110 0b11100100
    145,425         = 0b00011001 0b00011010
    235,236         = 0b00010110 0b00100110
    368,678         = 0b10100100 0b11100000
    378,367         = 0b11000100 0b01100100
    356,256         = 0b00110100 0b00110010
    125,124         = 0b00010011 0b00001011
    */

    //
    std::string a,b,c,d;//those chars are output
    int shift{10240};
    int keyA{0},keyB{0},keyC{0},keyD{0};

    //calculate key for each symbol
    //a:
    if(i%48==0) {keyA=0b00001001;keyB=0b00001001;}//a=14,b=14
    else if(i%48==1) {keyA=0b00001000;keyB=0b00001001;keyC=0b00000001;}
    else if(i%48==2) {keyB=0b00001001;keyC=0b00001001;}
    else if(i%48==3) {keyB=0b00001000;keyC=0b00001001;keyD=0b00000001;}
    else if(i%48==4) {keyC=0b00001001;keyD=0b00001001;}
    else if(i%48==5) {keyC=0b00001000;keyD=0b00011001;}
    else if(i%48==6) {keyD=0b00011011;}
    else if(i%48==7) {keyC=0b00010000;keyD=0b11010;}
    else if(i%48==8 ||i%48==40) {keyC=0b00010010;keyD=0b00010010;}
    else if(i%48==9 ||i%48==41) {keyA=0b0;keyB=0b00010000;keyC=0b00010010;keyD=0b00000010;}
    else if(i%48==10||i%48==42) {keyA=0b0;keyB=0b00010010;keyC=0b00010010;keyD=0b0;}
    else if(i%48==11||i%48==43) {keyA=0b00010000;keyB=0b00010010;keyC=0b00000010;keyD=0b0;}
    else if(i%48==12||i%48==44) {keyA=0b00010010;keyB=0b00010010;keyC=0b0;keyD=0b0;}
    else if(i%48==13) {keyA=0b00010110;keyB=0b00000010;keyC=0b0;keyD=0b0;}
    else if(i%48==14) {keyA=0b00110110;keyB=0b0;keyC=0b0;keyD=0b0;}
    else if(i%48==15) {keyA=0b00100110;keyB=0b00000100;keyC=0b0;keyD=0b0;}
    else if(i%48==16||i%48==32) {keyA=0b00100100;keyB=0b00100100;keyC=0b0;keyD=0b0;}
    else if(i%48==17||i%48==33) {keyA=0b00100000;keyB=0b00100100;keyC=0b00000100;keyD=0b0;}
    else if(i%48==18||i%48==34) {keyA=0b0;keyB=0b00100100;keyC=0b00100100;keyD=0b0;}
    else if(i%48==19||i%48==35) {keyA=0b0;keyB=0b00100000;keyC=0b00100100;keyD=0b00000100;}
    else if(i%48==20||i%48==36) {keyA=0b0;keyB=0b0;keyC=0b00100100;keyD=0b00100100;}
    else if(i%48==21) {keyA=0b0;keyB=0b0;keyC=0b00100000;keyD=0b10100100;}
    else if(i%48==22) {keyA=0b0;keyB=0b0;keyC=0b0;keyD=0b11100100;}
    else if(i%48==23) {keyA=0b0;keyB=0b0;keyC=0b10000000;keyD=0b11100000;}
    else if(i%48==24) {keyA=0b0;keyB=0b0;keyC=0b11000000;keyD=0b11000000;}
    else if(i%48==25) {keyA=0b0;keyB=0b10000000;keyC=0b11000000;keyD=0b01000000;}
    else if(i%48==26) {keyA=0b0;keyB=0b11000000;keyC=0b11000000;keyD=0b0;}
    else if(i%48==27) {keyA=0b10000000;keyB=0b11000000;keyC=0b01000000;keyD=0b0;}
    else if(i%48==28) {keyA=0b11000000;keyB=0b11000000;keyC=0b0;keyD=0b0;}
    else if(i%48==29) {keyA=0b11000100;keyB=0b01000000;keyC=0b0;keyD=0b0;}
    else if(i%48==30) {keyA=0b11100100;keyB=0b0;keyC=0b0;keyD=0b0;}
    else if(i%48==31) {keyA=0b01100100;keyB=0b00000100;keyC=0b0;keyD=0b0;}
    else if(i%48==37) {keyA=0b0;keyB=0b0;keyC=0b00100000;keyD=0b00110100;}
    else if(i%48==38) {keyA=0b0;keyB=0b0;keyC=0b0;keyD=0b00110110;}
    else if(i%48==39) {keyA=0b0;keyB=0b0;keyC=0b00010000;keyD=0b00110010;}
    else if(i%48==45) {keyA=0b00010011;keyB=0b00000010;keyC=0b0;keyD=0b0;}
    else if(i%48==46) {keyA=0b00011011;keyB=0b0;keyC=0b0;keyD=0b0;}
    else if(i%48==47) {keyA=0b00001011;keyB=0b00000001;keyC=0b0;keyD=0b0;}
    

    a=unicode_to_utf8(keyA+shift);
    b=unicode_to_utf8(keyB+shift);
    c=unicode_to_utf8(keyC+shift);
    d=unicode_to_utf8(keyD+shift);

    std::cout<<a<<b<<c<<d<<" ";
    /*
    should print that:
⠉⠉⠀⠀  
⠈⠉⠁⠀  
⠀⠉⠉⠀  
⠀⠈⠉⠁  
⠀⠀⠉⠉  
⠀⠀⠈⠙  
⠀⠀⠀⠛  
⠀⠀⠐⠚  
⠀⠀⠒⠒  
⠀⠐⠒⠂  
⠀⠒⠒⠀  
⠐⠒⠂⠀  
⠒⠒⠀⠀  
⠖⠂⠀⠀  
⠶⠀⠀⠀  
⠦⠄⠀⠀  
⠤⠤⠀⠀  
⠠⠤⠄⠀  
⠀⠤⠤⠀  
⠀⠠⠤⠄  
⠀⠀⠤⠤  
⠀⠀⠠⢤  
⠀⠀⠀⣤  
⠀⠀⢀⣠  
⠀⠀⣀⣀  
⠀⢀⣀⡀  
⠀⣀⣀⠀  
⢀⣀⡀⠀  
⣀⣀⠀⠀  
⣄⡀⠀⠀  
⣤⠀⠀⠀  
⡤⠄⠀⠀  
⠤⠤⠀⠀  
⠠⠤⠄⠀  
⠀⠤⠤⠀  
⠀⠠⠤⠄  
⠀⠀⠤⠤  
⠀⠀⠠⠴  
⠀⠀⠀⠶  
⠀⠀⠐⠲  
⠀⠀⠒⠒  
⠀⠐⠒⠂  
⠀⠒⠒⠀  
⠐⠒⠂⠀  
⠒⠒⠀⠀  
⠓⠂⠀⠀  
⠛⠀⠀⠀  
⠋⠁⠀⠀  
    */
}