#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, sum;
int arr[1000];

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) cin >> arr[i]; // 배열 입력

	sort(arr, arr + N, greater<>()); // 배열 내림차순 정렬

	int firstLargest = arr[0]; // 첫 번째로 큰 수
	int secondLargest = arr[1]; // 두 번째로 큰 수

	while (M > 0)
	{
		for (int i = 0; i < K; i++) // 큰 수를 K번 더하고, 더하는 횟수(M)를 감소 시킴
		{
			sum += firstLargest;
			M--;
		}
		if (M > 0) // 아직 더할 횟수(M)이 남아있다면, 두 번째로 큰 수를 한번 더 더하고, M를 감소 시킴
		{
			sum += secondLargest;
			M--;
		}
	}

	cout << sum;

	return 0;
}
