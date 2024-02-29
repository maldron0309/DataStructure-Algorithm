#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, res;
	cin >> N >> M;  // N: ���� ��, M: ���� ���� �Է¹���

	for (int i = 0; i < N; i++)  // �� �࿡ ����
	{
		int minValue = 10001;  // ���� �ּҰ��� ������ ����. �ʱⰪ�� ����� ū ���� ����

		for (int j = 0; j < M; j++)  // �ش� ���� �� ���� ����
		{
			int x;
			cin >> x;  // �� ���� ���� �Է¹���
			minValue = min(minValue, x);  // �Է¹��� ���� ������ �ּҰ� �� �� ���� ���� �ּҰ����� ����
		}

		res = max(res, minValue);  // ������� ã�� ���� �ּҰ� �� ���� ū ���� res�� ����
	}

	cout << res << '\n';  // ��� ���
}
