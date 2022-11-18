// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/939f8926366848a8a2cccb6e4eb97bf5
#include <bits/stdc++.h>

using namespace std;

vector<int> g[32005];
int indeg[32005];
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int v1, v2; cin >> v1 >> v2;     
        indeg[v2]++;
        g[v1].push_back(v2);
    }
    
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) pq.push(i);
    
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        
        for (int nxt : g[cur]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) pq.push(nxt);
        }
        
        ans.push_back(cur);
    }
    
    for (int i : ans)
        cout << i << ' ';
}