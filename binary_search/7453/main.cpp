// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/39ce9468299147b5be736b2f372dc5db
#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], d[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, ans = 0; cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        string input; cin >> input;
        for (int j = 0; j < input.length(); j++)
            a[i][j+1] = input[j] - '0';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) continue;
            d[i][j] = min({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + 1;
            ans = max(ans, d[i][j]);
        }
    }
    
    cout << ans*ans;
}