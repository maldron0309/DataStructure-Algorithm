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
		// N이 K로 나누어 떨어지는 수가 될 때가지 빼기
		int target = (N / K) * K;
		res += (N - target);
		N = target;

		// N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
		if (N < K) break;

		// K로 나누기
		res++;
		N /= K;
	}

	// 마지막으로 남은 수에 대하여 1씩 빼기
	res += (N - 1);
	cout << res << '\n';
}