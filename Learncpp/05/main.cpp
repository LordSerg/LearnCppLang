#include <iostream>
bool isPrime(int n)
{
    return (n==2||n==3||n==5||n==7);
}
void print(int i)
{
    std::cout<<i;
}
void q2(double x, double y, char op)
{
    std::cout<<x<<" "<<op<<" "<<y<<" = ";
    if(op == '+')std::cout<<x+y;
    if(op == '-')std::cout<<x-y;
    if(op == '*')std::cout<<x*y;
    if(op == '/')std::cout<<x/y;
    std::cout<<std::endl;
}
void fallenBall(double h, int sec = 0)
{
    std::cout<<"At "<<sec<<" seconds, the ball is at height: "<<(h-(sec*sec*9.8/2.0))<<" meters"<<std::endl;
    ++sec;
    if((h-(sec*sec*9.8/2.0))>0)
        fallenBall(h,sec);
    else
        std::cout<<"At "<<sec<<" seconds, the ball is on the ground.";
}
int main()
{
#if 0
    std::cout<<"sizeof(int) = "<<                                         sizeof(int)<<std::endl;
    std::cout<<"sizeof(sizeof(int)) = "<<                                 sizeof(sizeof(int))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(int))) = "<<                         sizeof(sizeof(sizeof(int)))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(int)))) = "<<                 sizeof(sizeof(sizeof(sizeof(int))))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(sizeof(int))))) = "<<         sizeof(sizeof(sizeof(sizeof(sizeof(int)))))<<std::endl;
    std::cout<<"sizeof(sizeof(sizeof(sizeof(sizeof(sizeof(int)))))) = "<< sizeof(sizeof(sizeof(sizeof(sizeof(sizeof(int))))))<<std::endl;
    float a{0.0f};
    std::cout<<a<<std::endl;
    std::cout<<(!a)<<std::endl;
    std::cout<<(!(!a))<<std::endl;
    for(int i{};i<1;++i)
    {
        std::cout<<"\\a was called"<<'\a'<<std::endl;
    }
#endif

#if 0
    //lesson 4.10, q2
    std::cout<<"enter an integer 0 through 9: ";
    int n;
    std::cin>>n;
    std::cout<<"The digit is "<<(isPrime(n)?"":"not ")<<"prime";
    //lesson 4.12, q1
    char ch{};
    std::cout<<"Enter a single character: ";
    std::cin>>ch;
    std::cout<<"You rntered \'"<<ch<<"\', which has ASCII code "<<static_cast<int>(ch)<<std::endl;
    
    //lesson 4.12, q1
    char ch{};
    std::cout<<"Enter a single character: ";
    std::cin>>ch;
    std::cout<<"You rntered \'"<<ch<<"\', which has ASCII code ";
    print(ch);
    std::cout<<std::endl;

    //4.x
    //qwestion 2
    double x,y;
    char op;
    std::cout<<"Enter first float number: ";
    std::cin>>x;
    std::cout<<"Enter first float number: ";
    std::cin>>y;
    std::cout<<"Enter math operator (+,-,* or /): ";
    std::cin>>op;
    if(op=='+'||op=='-'||op=='*'||op=='/')
        q2(x,y,op);
#endif

    //4.x
    //qwestion 3
    /*Write a short program to simulate a ball being dropped off of a tower.
     To start, the user should be asked for the height of the tower in meters.
     Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
     Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
     The ball should not go underneath the ground (height 0).
    */
    int h{};
    std::cout<<"Enter the height of the tower (in meters): ";
    std::cin>>h;
    fallenBall(h);
    return 0;
}