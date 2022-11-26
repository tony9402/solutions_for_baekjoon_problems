// Authored by : hji7599
// Co-authored by : -
// Link : http://boj.kr/56b6f7aea4dc46429e4963e388839025

#include<bits/stdc++.h>
using namespace std;
int n, c;
char ans[16];
char a[16];
void func(int k, int idx) {
    // 암호의 길이가 n이 된 경우
    if(k == n) {
        // 모음(v)과 자음(c)의 개수를 센다.
        int v = 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i]=='a'||ans[i] =='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u') v++;
            else c++;
        }
        // 모음이 1개 이상이고 자음이 2개 이상인 경우 출력한다.
        if(v >= 1 && c >= 2) {
            for(int i = 0; i < n; i++) {
                cout << ans[i];
            }
            cout << '\n';
        }
        return;
    }
    // 백트래킹 수행
    for(int i = idx+1; i < c; i++) {
        ans[k] = a[i];
        func(k+1, i);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    for(int i = 0; i < c; i++) cin >> a[i];
    sort(a, a+c);
    func(0, -1);
}