// Authored by : gyeong_sun
// Co-authored by : -
// Link : http://boj.kr/94b6b5913c2b467d9b3ecf39fa9fd4b0

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int arr[10] = { 0 };
	cin >> n >> k;
	int cnt = 0;

	for (int i = 0; i < n; i++)  cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {	 //n이 오름차순으로 주어진다. 
		cnt += k / arr[i];
		k %= arr[i];
	}

	cout << cnt;

	return 0;
}