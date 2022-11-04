// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/f9b92c1f899a4146bdf39d4e2a4a9f77

#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {

	if (n < 2) {
		return false;
	}
	else {
		for (int i = 2; i * i <= n; i++ ) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

}

void ans(int n) {
	int tmp = n;
	int next = 0;
	map<int, int> record;
	while (true) {
		while(tmp) {
			next = next + pow(tmp % 10, 2);
			tmp = tmp / 10;
		}
		tmp = next;
		next = 0;
		if (tmp == 1) {
			cout << n << '\n';
			return;
		}
		if (record.find(tmp) != record.end()) {
			return;
		}
		record.insert(make_pair(tmp, 0));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (prime(i)) {
			ans(i);
		}
	}


	return 0;
}
