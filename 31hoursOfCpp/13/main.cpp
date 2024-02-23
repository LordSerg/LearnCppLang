#include <iostream>


class A
{
    public:
        A()
        {
            std::cout<<"A default construct\n";
        }
        A(const A& kek):
        a(kek.a),b(kek.b),c(kek.c)
        {
            std::cout<<"A custom copy construct\n";
        }
        void print()
        {
            std::cout<<"a = "<<a<<"\n";
        }
    public:
        int a{};
    protected:
        int b{};
    private:
        int c{};
};

class B : public A
{
    public:
        B()
        {
            std::cout<<"B default construct\n";
        }
        B(const B& aboba):
        A(aboba)
        {
            std::cout<<"B custom copy construct\n";
        }
        B(const A& aboba):
        A(aboba)
        {
            std::cout<<"B custom copy from A-object construct\n";
        }
        void some_f()
        {
            a=0;
            b=0;
            //c=0;//
        }
        void print()
        {
            std::cout<<"b = "<<b<<"\n";
        }
        using A::b;
};
class C : public B
{
    public: 
        C()
        {
            std::cout<<"C default construct\n";
        }
        C(const C& lel):
        B(lel)
        {
            std::cout<<"C custom copy construct\n";
        }
        void some_other_f()
        {
            //a=1;
            b=1;
            //c=1;
        }
        void print()
        {
            std::cout<<"c = "<<b<<"\n";
        }
};
int main()
{
    /*
    A a;
    B b;
    C c; 
    //a.b =1;
    b.b =1;
    //c.b =1;
    b.some_f();
    //c.some_f();
    c.some_other_f();
    */
    
    /*
    A a;
    A a2(a);
    std::cout<<"-------------\n";
    B b;
    B b2(a);
    //std::cout<<"-------------\n";
    //C c;
    //C c2(c);
    */
    
    A a;
    a.print();
    B b;
    b.print();
    C c;
    c.print();
    std::cout<<"-------------\n";
    c.B::print();
    return 0;
}