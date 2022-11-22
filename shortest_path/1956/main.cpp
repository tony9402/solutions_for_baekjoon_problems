// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/99efabba41724268a801f3d92eef8eb1

#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int v, e;
	int ans = INT_MAX;

	cin >> v >> e;

	int node[401][401];

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			node[i][j] = INF;
		}
	}

	for (int i = 1; i <= v; i++) {
		node[i][i] = 0;
	}

	for (int i = 0; i < e; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		node[start][end] = weight;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (node[i][k] + node[k][j] < node[i][j]) {
					node[i][j] = node[i][k] + node[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) {
				continue;
			}
			if (node[i][j] == INF) {
				continue;
			}
			if (node[j][i] == INF) {
				continue;
			}
			ans = min(ans, node[i][j] + node[j][i]);
		}
	}

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}

