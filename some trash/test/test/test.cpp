// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;
bool bracets_check(const std::string& str)
{
    if (str.length() % 2 == 1)
        return false;//якщо непарна кількість символів, то і якійсь дужці нема пари, а отже щось не так
    int cnt_round = 0;
    int cnt_fig = 0;
    int cnt_square = 0;
    //попередня перевірка строки, чи у кожної відкритої дужки є закрита:
    for (int i = 0; i < str.length(); i++)
    {
        //рахуємо відкриті дужки:
        if (str[i] == '(')cnt_round++;
        else if (str[i] == '{')cnt_fig++;
        else if (str[i] == '[')cnt_square++;
        //рахуємо закриті дужки:
        else if (str[i] == ')')
        {
            cnt_round--;//закриваємо дужку
            if (cnt_round < 0)//якщо дужка закрилася до того, як була відкрита
                return false;
        }
        else if (str[i] == '}')
        {
            cnt_fig--;//закриваємо дужку
            if (cnt_fig < 0)//якщо дужка закрилася до того, як була відкрита
                return false;
        }
        else if (str[i] == ']')
        {
            cnt_square--;//закриваємо дужку
            if (cnt_square < 0)//якщо дужка закрилася до того, як була відкрита
                return false;
        }
    }
    if (!(cnt_fig == 0 && cnt_round == 0 && cnt_square == 0))
        return false;
    //якщо функція дійде сюди, то перевіряємо на правильність послідовності дужок
    std::stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {//якщо дужка відкриваюча, то додаємо її о стеку
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            stack.push(str[i]);
        //якщо дужка закриваюча, то порівнюємо її з останнім елементом стеку
        //якщо вони співпали - то все добре, 
        //якщо ні - то виходимо з функції зі значенням false
        else if (str[i] == ')')
        {
            char ch = stack.top();
            if (stack.top() == '(')
                stack.pop();
            else
                return false;
        }
        else if (str[i] == '}')
        {
            if (stack.top() == '{')
                stack.pop();
            else
                return false;
        }
        else if (str[i] == ']')
        {
            if (stack.top() == '[')
                stack.pop();
            else
                return false;
        }
    }
    return true;//якщо строка пройшла всы перевырки, то з нею все добре
}
class A {
public:
    virtual void print()const { cout << "AC"; }
    virtual void print() { cout << "A"; }

};
class B {
public:
    virtual void print()const { cout << "AC"; }
    virtual void print() { cout << "A"; }

};
int main()
{
    /*
    std::string a = "[{]}";
    std::cout << boolalpha << bracets_check(a);
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
