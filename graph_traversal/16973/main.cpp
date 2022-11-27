//Authored by : ccocco0609
//Co-authored by : -
//Link : http://boj.kr/52e718bbc8cf4dcbb019f7d6118bd552
#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

int ans;
int n, m;
int h, w;
int start_x, start_y;
int end_x, end_y;
int plane[SIZE][SIZE];
bool visited[SIZE][SIZE] = { false, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool check_block(int y, int x, int go) {
	if (go == 0) {
		int ny = y + h - 1;
		for (int i = x; i < x + w; i++) {
			if (plane[ny][i] == 1) {
				return false;
			}
		}
	}
	else if (go == 1) {
		for (int i = x; i < x + w; i++) {
			if (plane[y][i] == 1) {
				return false;
			}
		}
	}
	else if (go == 2) {
		int nx = x + w - 1;
		for (int i = y; i < y + h; i++) {
			if (plane[i][nx] == 1) {
				return false;
			}
		}
	}
	else {
		for (int i = y; i < y + h; i++) {
			if (plane[i][x] == 1) {
				return false;
			}
		}
	}

	return true;
}

void bfs() {

	queue<tuple<int, int, int>> q;

	visited[start_y][start_x] = true;
	q.push(make_tuple(start_y, start_x, 0));

	while (!q.empty()) {
		int cur_y = get<0>(q.front());
		int cur_x = get<1>(q.front());
		int length = get<2>(q.front());
		q.pop();
		if (cur_x == end_x && cur_y == end_y) {
			ans = length;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_y < 0) {
				continue;
			}
			if (next_x + w > m || next_y + h > n) {
				continue;
			}
			if (visited[next_y][next_x]) {
				continue;
			}
			if (check_block(next_y, next_x, i)) {
				q.push(make_tuple(next_y, next_x, length + 1));
				visited[next_y][next_x] = true;
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> plane[i][j];
		}
	}

	cin >> h >> w;
	cin >> start_y >> start_x;
	cin >> end_y >> end_x;

	start_x--;
	start_y--;
	end_x--;
	end_y--;

	ans = INT_MAX;

	bfs();

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}

