// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/af40b557942e45669e7607e9e7e63a6b
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll d[205][205];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
    
    int n, k, mod = 1000000000; cin >> n >> k;
    
    for (int i = 0; i <= n; i++) {
        d[i][1] = 1;
        
        for (int j = 2; j <= k; j++) {
            for (int l = 0; l <= i; l++) {
                d[i][j] = (d[i][j] + d[l][j-1]) % mod;
            }
        }
    }
    
    cout << d[n][k];
}