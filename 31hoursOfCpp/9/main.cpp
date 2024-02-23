#include <iostream>
#include "compare.h"
int main()
{
    /*
    double a{12};
    double b{21};
    std::cout<<"max("<<a<<", "<<b<<") = "<<max(a,b)<<std::endl;
    std::cout<<"min("<<a<<", "<<b<<") = "<<min(a,b)<<std::endl;
    return 0;*/

    /*
    [](){
        std::cout<<"inside1";
        auto l2 = []()->std::string{
            std::cout<<" inside2";
            return "inside2";
        }();
        std::cout<<" inside1";
    }();*/

    /*
    int qwerty{1000};
    auto swap = [qwerty](int &a,int &b){
        std::cout<<"qwerty = "<<qwerty<<std::cout;
        a+=b;
        b=a-b;
        a-=b;
    };

    int in1{5};
    int in2{10};
    std::cout<<"before swap(): in1{"<<in1<<"}, in2{"<<in2<<"};"<<std::endl;
    swap(in1,in2);
    std::cout<<"after swap(): in1{"<<in1<<"}, in2{"<<in2<<"};"<<std::endl;
    */

    auto vglambda = [](auto printer)
    {
        return [=](auto&&... ts) // generic lambda, ts is a parameter pack
        { 
            printer(std::forward<decltype(ts)>(ts)...);
            // nullary lambda (takes no parameters):
            return [=] { printer(ts...); };
        };
    };
 
    auto p = vglambda([](auto v1, auto v2, auto v3)
    {
        std::cout << v1 << v2 << v3;
    });
    auto q = p(1, 'a', 3.14); // outputs 1a3.14
    q();

    /*
    double a{12};
    double b{21};
    auto func = [&]()
    {
        std::cout<<"a = "<<a<<std::endl;
        std::cout<<"b = "<<b<<std::endl;
        std::cout<<"a*b = "<<(a*b)<<std::endl;
        a++;
        b++;
        std::cout<<"a = "<<a<<std::endl;
        std::cout<<"b = "<<b<<std::endl;
    };
    func();
    std::cout<<"outside lambda:"<<std::endl;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;*/
}