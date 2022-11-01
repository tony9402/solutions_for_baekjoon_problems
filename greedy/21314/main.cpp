// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/287d5dddc2114cb69d82fdc4196157f5

#include <bits/stdc++.h>
using namespace std;

string min_value(string mk) {

	string ans = "";

	for (int i = 0; i < mk.size(); i++) {
		if (mk[i] == 'M') {
			string tmp = "1";
			for (int j = i + 1; j < mk.size(); j++) {
				if (mk[j] == 'K') {
					i = j - 1;
					break;
				}
				tmp += "0";
				i = j;
			}
			ans = ans + tmp;
		}
		else if (mk[i] == 'K') {
			ans = ans + "5";
		}
	}
	return ans;
}

string max_value(string mk) {

	string ans = "";
	string find_m = "";

	for (int i = 0; i < mk.size(); i++) {
		if (mk[i] == 'M') {
			find_m += "1";
		}
		else if (mk[i] == 'K') {
			string tmp = "5";
			for (int j = 0; j < find_m.size(); j++) {
				tmp += "0";
			}
			find_m = "";
			ans = ans + tmp;
		}
		if (i == mk.size() - 1 && mk[i] == 'M') {
			ans = ans + find_m;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string mk = "";

	cin >> mk;

	cout << max_value(mk) << '\n';
	cout << min_value(mk);

	return 0;
}
