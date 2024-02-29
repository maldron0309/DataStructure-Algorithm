#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, res;
	cin >> N >> M;  // N: 행의 수, M: 열의 수를 입력받음

	for (int i = 0; i < N; i++)  // 각 행에 대해
	{
		int minValue = 10001;  // 행의 최소값을 저장할 변수. 초기값은 충분히 큰 수로 설정

		for (int j = 0; j < M; j++)  // 해당 행의 각 열에 대해
		{
			int x;
			cin >> x;  // 각 열의 값을 입력받음
			minValue = min(minValue, x);  // 입력받은 값과 현재의 최소값 중 더 작은 값을 최소값으로 설정
		}

		res = max(res, minValue);  // 현재까지 찾은 행의 최소값 중 가장 큰 값을 res에 저장
	}

	cout << res << '\n';  // 결과 출력
}
