#include <iostream>
#include <vector>

using namespace std;


class Stack
{
	int arr[100];
	int index = -1;
public:

	int top()
	{
		if (empty())
		{

			throw runtime_error("Stack is empty");
		}
		else
		{
			return arr[index];
		}
	}

	void pop()
	{
		if (!empty())
		{
			--index;
		}
		return;
	}

	void push(int val)
	{
		if (index == 99)
		{
			cout << "FULL" << "\n";
		}
		else
		{
			arr[++index] = val;
		}
	}

	bool empty()
	{
		return index == -1;
	}

};

int main()
{
	Stack S;

	for (int i = 0; i < 5; i++) {
		S.push(i);
	}

	for (; !S.empty(); S.pop()) {

		cout << S.top() << "\n";
	}
}