#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, sum;
int arr[1000];

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) cin >> arr[i]; // �迭 �Է�

	sort(arr, arr + N, greater<>()); // �迭 �������� ����

	int firstLargest = arr[0]; // ù ��°�� ū ��
	int secondLargest = arr[1]; // �� ��°�� ū ��

	while (M > 0)
	{
		for (int i = 0; i < K; i++) // ū ���� K�� ���ϰ�, ���ϴ� Ƚ��(M)�� ���� ��Ŵ
		{
			sum += firstLargest;
			M--;
		}
		if (M > 0) // ���� ���� Ƚ��(M)�� �����ִٸ�, �� ��°�� ū ���� �ѹ� �� ���ϰ�, M�� ���� ��Ŵ
		{
			sum += secondLargest;
			M--;
		}
	}

	cout << sum;

	return 0;
}
