// Authored by : hji7599
// Co-authored by : -
// Link : http://boj.kr/441618bb4a034e1195d84494b5c0908d

#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int l;
        int cx, cy;
        int gx, gy;
        cin >> l;
        cin >> cx >> cy;
        cin >> gx >> gy;
        queue<pair<int, int>> q;
        int vis[l][l];
        fill(&vis[0][0], &vis[l-1][l-1], -1);
        q.push({cx, cy});
        vis[cx][cy] = 0;
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(vis[nx][ny] > -1) continue;
                vis[nx][ny] = vis[cur.X][cur.Y]+1;
                q.push({nx, ny});
            }
        }
        cout << vis[gx][gy] << '\n';
    }
}