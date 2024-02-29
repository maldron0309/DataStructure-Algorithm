#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	int res = 0;
	cin >> N >> K;

	while (true)
	{
		// N�� K�� ������ �������� ���� �� ������ ����
		int target = (N / K) * K;
		res += (N - target);
		N = target;

		// N�� K���� ���� �� (�� �̻� ���� �� ���� ��) �ݺ��� Ż��
		if (N < K) break;

		// K�� ������
		res++;
		N /= K;
	}

	// ���������� ���� ���� ���Ͽ� 1�� ����
	res += (N - 1);
	cout << res << '\n';
}