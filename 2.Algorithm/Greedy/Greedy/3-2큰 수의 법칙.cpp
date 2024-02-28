#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{

	vector<int> v;
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int first = v[N - 1];
	int second = v[N - 2];

	int cnt = (M / (K + 1)) * K;
	cnt += M % (K + 1);

	int result = 0;
	result += cnt * first;
	result += (M - cnt) * second;

	cout << result << endl;

}
