// Authored by : hji7599
// Co-authored by : -
// Link : http://boj.kr/8a17589373334ccd8d778badabf32a2f

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string arr[5];
bool isused[25];
int vis[5][5];
int ans;

void select(int idx, int cnt) {
    if (cnt == 7) {
        queue<pair<int, int>> q;
        fill(&vis[0][0], &vis[4][5], 0);
        int y = 0;
        for (int i = 0; i < 25; i++) {
            if (!isused[i]) continue;
            vis[i / 5][i % 5] = true;
            q.push({i / 5, i % 5});
            if (arr[i / 5][i % 5] == 'Y')
                y++;
            break;
        }
        int cnt = 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    continue;
                if (vis[nx][ny])
                    continue;
                if (!isused[nx * 5 + ny])
                    continue;
                vis[nx][ny] = 1;
                if (arr[nx][ny] == 'Y')
                    y++;
                q.push({nx, ny});
                cnt++;
            }
        }
        if (cnt >= 7 && y <= 3) {
            ans++;
            //cout << ans;
        }
        return;
    }
    for (int i = idx; i < 25; i++) {
        if (isused[i])
            continue;
        isused[i] = 1;
        select(i, cnt + 1);
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    for (int i = 0; i < 5; i++) {
        cin >> str;
        arr[i] = str;
    }
    select(0, 0);
    cout << ans;
}