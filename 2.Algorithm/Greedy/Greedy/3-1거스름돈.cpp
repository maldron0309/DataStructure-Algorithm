#include<iostream>

using namespace std;

int main()
{
	int n = 1260;
	int count = 0;
	int coinType[4] = { 500, 100, 50, 10 }; // ū ������ ȭ����� ���ʴ�� Ȯ��

	for (int i = 0; i < 4; i++)
	{
		int coin = coinType[i];
		count += n / coin; // �ش� ȭ��� �Ž��� �� �� �ִ� ������ ���� ����
		n %= coin;
	}
	cout << count << '\n';
}