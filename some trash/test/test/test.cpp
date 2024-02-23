// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;
bool bracets_check(const std::string& str)
{
    if (str.length() % 2 == 1)
        return false;//���� ������� ������� �������, �� � ����� ����� ���� ����, � ���� ���� �� ���
    int cnt_round = 0;
    int cnt_fig = 0;
    int cnt_square = 0;
    //��������� �������� ������, �� � ����� ������� ����� � �������:
    for (int i = 0; i < str.length(); i++)
    {
        //������ ������ �����:
        if (str[i] == '(')cnt_round++;
        else if (str[i] == '{')cnt_fig++;
        else if (str[i] == '[')cnt_square++;
        //������ ������ �����:
        else if (str[i] == ')')
        {
            cnt_round--;//��������� �����
            if (cnt_round < 0)//���� ����� ��������� �� ����, �� ���� �������
                return false;
        }
        else if (str[i] == '}')
        {
            cnt_fig--;//��������� �����
            if (cnt_fig < 0)//���� ����� ��������� �� ����, �� ���� �������
                return false;
        }
        else if (str[i] == ']')
        {
            cnt_square--;//��������� �����
            if (cnt_square < 0)//���� ����� ��������� �� ����, �� ���� �������
                return false;
        }
    }
    if (!(cnt_fig == 0 && cnt_round == 0 && cnt_square == 0))
        return false;
    //���� ������� ���� ����, �� ���������� �� ����������� ����������� �����
    std::stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {//���� ����� ����������, �� ������ �� � �����
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            stack.push(str[i]);
        //���� ����� ����������, �� ��������� �� � ������� ��������� �����
        //���� ���� ������� - �� ��� �����, 
        //���� � - �� �������� � ������� � ��������� false
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
    return true;//���� ������ ������� ��� ���������, �� � ��� ��� �����
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
