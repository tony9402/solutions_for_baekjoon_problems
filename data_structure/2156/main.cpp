// Authored by : ccocco0609
// Co-authored by : tony9402
// Link : http://boj.kr/1a58200da0374f249178f1d258ff4c90

#include <bits/stdc++.h>
using namespace std;

int wine[10001] = { 0, };
int dp[10001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n = 0;
    
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(wine[i] + dp[i - 2], max(wine[i] + wine[i - 1] + dp[i - 3], dp[i-1]));
	}

	cout << dp[n];

	return 0;
}
