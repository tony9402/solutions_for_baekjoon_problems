//Authored by : ccocco0609
//Co-authored by : -
//Link : http://boj.kr/ebad50ddb17b4ec193fcf9a2f06fd979
#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[101];
bool circle[101];
int arr[101];
vector<int> ans;

void dfs(int start, int cur) {

	if (visited[cur]) {
		if (circle[cur]) {
			return;
		}
		if (start == cur) {
			for (int i = 1; i <= n; i++) {
				if (visited[i]) {
					circle[i] = true;
					ans.push_back(i);
				}
			}
			return;
		}
		else {
			return;
		}
	}

	visited[cur] = true;
	dfs(start, arr[cur]);
	visited[cur] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		circle[i] = false;
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!circle[i]) {
			dfs(i, i);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}

