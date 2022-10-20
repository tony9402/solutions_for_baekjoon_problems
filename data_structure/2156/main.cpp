// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/1a58200da0374f249178f1d258ff4c90
#include <bits/stdc++.h>
using namespace std;

// 전역에 배열 또는 변수를 선언한 경우 0으로 초기화 됩니다.
int wine[10001];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    
    for (int i = 1; i <= N; i++) cin >> wine[i];

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = max(wine[i] + dp[i - 2], max(wine[i] + wine[i - 1] + dp[i - 3], dp[i - 1]));
    }
    
    cout << dp[N];
    return 0;
}
