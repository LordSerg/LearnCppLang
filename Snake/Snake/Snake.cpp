#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
int x_s, y_s, x, y, length;
bool is_game = true;
bool is_food = false;
int Score=0;
void Game_over()
{
	for (int i = 0; i < 3; i++)
	{
		system("color 0C");
		Sleep(20);
		system("color C0");
		Sleep(20);
	}
	is_game = false;
}
bool KEY[256];
void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) 
			KEY[i] = 1; 
		else 
			KEY[i] = 0;
		i++;
	}
}
class Zmeyka
{
public:
	
	int X,Y,up,right;
	bool hd;//проверка на наличие "мозга" в элементе
	Zmeyka(){}
	Zmeyka(int coord_x, int coord_y, bool h)
	{
		X = coord_x;
		Y = coord_y;
		hd = h;
		if (hd)
		{
			up = 0;
			right = 1;
		}
	}
};
Zmeyka zzz[1000];
class Food
{
public:
	int X, Y;
	Food(){}
	Food(int x, int y)
	{
		X = x;
		Y = y;
	}
};
Food f;
bool is_snake(int h, int w, int n)
{
	bool k=false;
	for (int i = 0; i < n; i++)
		if (!((w == zzz[i].X) && (h == zzz[i].Y)))
			k = false;
		else
		{
			k = true;
			break;
		}
	return k;
}
void do_food()
{
rego:
	if (is_food==false)
	{
		int a, b;
		a = rand() % x;
		b = rand() % y;
		if (zzz[rand() % length].X == a && zzz[rand() % length].Y == b)
			goto rego;
		else
		{
			f = Food(a, b);
			is_food = true;
		}
	}
}
void next_step(int n, int r, int d)//n - количество звеньев
{
	for (int i = n - 1; i > 0; i--)
	{
		zzz[i].X = zzz[i - 1].X;
		zzz[i].Y = zzz[i - 1].Y;
	}
	if (is_snake(zzz[0].Y + d, zzz[0].X + r, n))
		Game_over();
	else
	{
		zzz[0].X += r;
		zzz[0].Y += d;
	}
	if (zzz[0].X == f.X && zzz[0].Y == f.Y)
	{
		length++;
		is_food = false;
		Score++;
		do_food();
	}

}
//Zmeyka resize[](Zmeyka x[])
//{
//	Zmeyka a [sizeof(x)+1];
//	for (int i = 0; i < sizeof(x); i++)
//	{
//		a[i] = x[i];
//	}
//	a[sizeof(x)] = a[sizeof(x) - 1];
//	//проверяем вектор направления хвоста:
//	if (x[sizeof(x) - 2].X == x[sizeof(x) - 1].X)
//	{//если хвост вертекален
//		if (x[sizeof(x) - 2].Y - x[sizeof(x) - 1].Y>0)
//		{//если хвост идет вниз
//			/*
//			 |		
//			 |	   ↓*
//			 |		* * * +
//			 |
//			*/
//
//		}
//		else
//		{//если звост идет вверх
//			/*
//			 |		
//			 |		* * * +
//			 |	   ↑*
//			 |		
//			*/
//
//		}
//	}
//	else
//	{//если хвост горизонтален
//		if (x[sizeof(x) - 2].X - x[sizeof(x) - 1].X>0)
//		{//если хвост идет вправо
//			/*
//			 |   →
//			 |	 * * * * +
//			 |	 
//			*/
//
//		}
//		else
//		{//если хвост идет влево
//			/*
//			 |			  ←
//			 |	  + * * * *
//			 |
//			*/
//
//		}
//	}
//	return a;
//}
int main()
{	
	Score = 0;
	//int x_s, y_s, x, y,length;
	length = 3;
	cout << "Width = ";
	cin >> x;
	cout << "Height = ";
	cin >> y;
	//*zzz = new Zmeyka[length];
	zzz[0] = Zmeyka(length, 0, true);//
	for (int i = 0; i < length; i++)
		zzz[i] = Zmeyka(length-i-1, 0, false);
	do_food();
	system("cls");
	//system("color ")
	/*char a;
	a = static_cast<char>(x);
	char b;
	b = static_cast<char>(y);
	const char z[26] = "mode con cols=" + a+" lines=" + b;
	system(z);*/
	Sleep(1000);
	int down, right;
	down = 0;
	right = 1;
	while (true)
	{//отслеживаем клавиатуру:
		GetKEY();
		if (KEY[40] && down != -1)
		{//down
			down = 1;
			right = 0;
		}
		if (KEY[39] && right != -1)
		{//right
			right = 1;
			down = 0;
		}
		if (KEY[38] && down != 1)
		{//up
			down = -1;
			right = 0;
		}
		if (KEY[37] && right != 1)
		{//left
			right = -1;
			down = 0;
		}
		if (KEY[32])//пробное(читерское) увеличение змейки
			length++;
		//делаем следующий шаг змейкой:
		next_step(length, right, down);
		if (is_game == false)break;
		for (int i = 0; i < length; i++)
		{
			if (zzz[i].Y >= y)
				zzz[i].Y = 0;
			if (zzz[i].X >= x)
				zzz[i].X = 0;
			if (zzz[i].Y < 0)
				zzz[i].Y = y - 1;
			if (zzz[i].X < 0)
				zzz[i].X = x - 1;
		}
		cout << "\n\n\n";
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < y; i++)
		{
			cout << "\t\t\t";
			for (int j = 0; j < x; j++)
			{
				if (is_snake(i, j, length))//если змея
					SetConsoleTextAttribute(handle, 10);
				else if (f.X == j && f.Y == i)//если еда
					SetConsoleTextAttribute(handle, 12);
				else//если поле
					SetConsoleTextAttribute(handle, 1);
				if (j == x - 1)
					cout << /*char(254) <<*/ "*|";
				else
					cout << /*char(254) <<*/ "* ";
			}
			cout << "\n";
		}
		//cout << "down = " << down << "\n";
		//cout << "right = " << right << "\n";
		//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 7);
		cout << "Score = " << Score << "\n";
		cout << "Coordinates of food:\n";
		cout << "X = " << f.X << "\n";
		cout << "Y = " << f.Y << "\n";
		//Game_over();
		Sleep(100);
		system("cls");
	}

	//setlocale(LC_ALL, "Russian");
	//DWORD l;
	//COORD point;
	//point.X = 0;
	//point.Y = 0;
	//HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	//char title[21] = "Консольная программа";
	//CharToOem((LPCWSTR)title, title);
	//SetConsoleTitle((LPCWSTR)title);
	//SetConsoleOutputCP(1251);
	//SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	//FillConsoleOutputAttribute(hout, 0, 2000, point, &l); // очистка экрана
	//for (int y = 0; y < 16; y++) {
	//	point.Y = y;
	//	FillConsoleOutputAttribute(hout, y << 4, 80, point, &l);
	//	SetConsoleCursorPosition(hout, point);
	//}
	//char c;
	//ReadFile(hin, &c, 1, &l, NULL);
	//system("mode con cols=100 lines=10");

	/*for (int i = 0; i <= 100; i++)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, i);
		cout << "This is namber: " << i << endl;
	}
	Sleep(1000);
	Game_over();*/
	return 0;
}


