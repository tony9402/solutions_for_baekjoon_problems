// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/e95e889a5dca4d00b6df83d7e673d101
#include <bits/stdc++.h>
using namespace std;

int p[1000005];

int find(int a) {
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    p[pb] = pa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t; cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        cout << "Scenario " << tc << ":\n";
        
        int n, k; cin >> n >> k;
        
        for (int i = 0; i < n; i++)
            p[i] = i;
        
        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            uni(a, b);
        }
        
        int m; cin >> m;
        
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            if (find(a) == find(b)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        
        cout << '\n';
    }
}