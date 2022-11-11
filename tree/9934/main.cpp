// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/8e877ca142bc4d4c8dce98501c54b0c8

#include <bits/stdc++.h>
using namespace std;

int building_num[1024];

void print_building(int start, int jump, int size) {
	
	int cur_idx = start;

	while (cur_idx < size) {
		cout << building_num[cur_idx] << " ";
		cur_idx += jump;
	}
	if (start == 0) {
		return;
	}
	else {
		cout << '\n';
		print_building(start / 2, jump / 2, size);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k = 0;
	int total_num;
	
	cin >> k;
	total_num = pow(2, k) - 1;

	for (int i = 0; i < total_num; i++) {
		cin >> building_num[i];
	}

	print_building(total_num / 2, total_num + 1, total_num);

	return 0;
}
