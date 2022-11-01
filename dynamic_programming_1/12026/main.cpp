//  Authored by : ccocco0609
//  Co-authored by : -
//  Link : http://boj.kr/7e8a8a5c22d24a7b925e753cd6491479

#include <bits/stdc++.h>
using namespace std;

int dp[1000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(dp, 1000, INT_MAX);
	dp[0] = 0;

	int n = 0;
	
	cin >> n;

	string block = "";

	cin >> block;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (block[i] == 'B') {
				if (block[j] == 'J') {
					if (dp[j] == INT_MAX) {
						continue;
					}
					int dis = (i - j) * (i - j) + dp[j];
					if (dp[i] > dis) {
						dp[i] = dis;
					}
				}
			}
			else if (block[i] == 'O') {
				if (block[j] == 'B') {
					if (dp[j] == INT_MAX) {
						continue;
					}
					int dis = (i - j) * (i - j) + dp[j];
					if (dp[i] > dis) {
						dp[i] = dis;
					}
				}
			}
			else if (block[i] == 'J') {
				if (block[j] == 'O') {
					if (dp[j] == INT_MAX) {
						continue;
					}
					int dis = (i - j) * (i - j) + dp[j];
					if (dp[i] > dis) {
						dp[i] = dis;
					}
				}
			}
		}
	}

	if (dp[n - 1] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << dp[n - 1];
	}
	
	return 0;
}
