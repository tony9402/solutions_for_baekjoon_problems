// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/6755219b408e46218d44617c0734b2eb

#include <bits/stdc++.h>
using namespace std;

#define SIZE 300001

int n, m, k, x;
vector<vector<int>> node;
bool visited[SIZE] = { false, };
int result[SIZE];

void bfs(int start, int length) {
	queue<pair<int, int>> que;
	que.push(make_pair(start, length));
	visited[start] = true;

	while (!que.empty()) {
		int cur = que.front().first;
		int cur_length = que.front().second;
		que.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i];
			if (!visited[next]) {
				if (cur_length + 1 > k) {
					continue;
				}
				que.push(make_pair(next, cur_length + 1));
				result[next] = cur_length + 1;
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k >> x;

	node.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int start;
		int end;
		cin >> start >> end;
		node[start].push_back(end);
	}

	bfs(x, 0);

	bool nothing = true;

	for (int i = 1; i <= n; i++) {
		if (result[i] == k) {
			nothing = false;
			cout << i << '\n';
		}
	}

	if (nothing) {
		cout << -1;
	}

	return 0;
}

