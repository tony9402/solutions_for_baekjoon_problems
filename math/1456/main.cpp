// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/39c1b326e6f143768e642a46f8050974

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001

bool prime[MAX];

void set_prime() {
	for (int i = 2; i*i <= MAX; i++) {
		if (prime[i]) {
			continue;
		}
		for (int j = i * i; j < MAX; j += i) {
			prime[j] = 1;
		}
	}
}

int almost_prime(long long a, long long b) {
	int ans = 0;
	for (long long i = 2; i*i <= b; i++) {
		if (!prime[i]) {
			int idx = 2;
			while (pow(i, idx) <= b) {
				if (pow(i, idx) >= a) {
					ans++;
				}
				idx++;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	int ans = 0;

	set_prime();

	cin >> a >> b;

	ans = almost_prime(a, b);

	cout << ans;

	return 0;
}