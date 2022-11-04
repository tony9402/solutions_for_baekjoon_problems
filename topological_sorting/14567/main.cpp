// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/c6253b67c0754395baad8b08ffbc5d5e
#include <bits/stdc++.h>
using namespace std;

int ans[1005], indeg[1005];
vector<int> g[1005];

void dfs(int cur) {
    for (auto nxt : g[cur]) {
        if (ans[nxt] >= ans[cur] + 1) continue;
        ans[nxt] = ans[cur] + 1;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        
        cin >> a >> b;
        
        indeg[b]++;
        g[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (indeg[i]) continue;
        ans[i] = 1;
        dfs(i);
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}