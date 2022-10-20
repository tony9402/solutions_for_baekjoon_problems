// Authored by : ccocco0609
// Co-authored by : tony9402
// Link : http://boj.kr/de37b0fcab5b4d13a414abb3040ee3f5

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> sum_vector;

	sum_vector.push_back(0);

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		sum_vector.push_back(sum_vector.back() + tmp);  // 누적 합을 저장
	}

	int m; cin >> m;

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		int result = sum_vector[j] - sum_vector[i - 1]; // 해당하는 범위의 누적합을 구함
		cout << result << '\n';
	}

	return 0;
}
