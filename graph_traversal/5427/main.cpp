// Authored by : hji7599
// Co-authored by : -
// Link : http://boj.kr/3f0d150100f645249f965108a018432d
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char board[1005][1005];
int vis[1005][1005];
int s_vis[1005][1005];

int bfs(queue<pair<int, int>>& qq, int h, int w) {
    while(!qq.empty()) {
        auto cur = qq.front(); qq.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                return s_vis[cur.X][cur.Y];
            }
            if(s_vis[nx][ny] > 0 || board[nx][ny] != '.') continue;
            if(vis[nx][ny] != 0 && s_vis[cur.X][cur.Y]+1 >= vis[nx][ny]) continue;
            s_vis[nx][ny] = s_vis[cur.X][cur.Y]+1;
            qq.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        queue<pair<int, int>> q;
        pair<int, int> sang;
        int w, h;
        cin >> w >> h;
        fill(&board[0][0], &board[h][w], 0);
        fill(&vis[0][0], &vis[h][w], 0);
        fill(&s_vis[0][0], &s_vis[h][w], 0);
        for(int i = 0; i < h; i++) {
            string line;
            cin >> line;
            for(int j = 0; j < w; j++) {
                board[i][j] = line[j];
                if(board[i][j] == '*') {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if(board[i][j] == '@') {
                    sang = {i, j};
                    s_vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(vis[nx][ny] > 0 || board[nx][ny] != '.') continue;
                vis[nx][ny] = vis[cur.X][cur.Y]+1;
                q.push({nx, ny});
            }
        }
        q.push(sang);

        int ans = bfs(q, h, w);
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}