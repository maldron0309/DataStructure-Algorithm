#include <iostream>
#include <vector>
using namespace std;

int x = 10;

int Func1()
{
	int y = x + 10;
	return y;
}

int Func2()
{
	int x = 100;
	return x;
}

void main()
{
	cout << "y = " << Func1() << '\n';
	cout << "y = " << Func2() << '\n';
	cout << "y = " << x << '\n';

}