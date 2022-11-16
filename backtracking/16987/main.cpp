// Authored by : hji7599
// Co-authored by : -
// Link : http://boj.kr/ab9ec0805ed44170aa409750433ed37f

#include<bits/stdc++.h>
using namespace std;
int n;
int s[10];
int w[10];
int answer;

void func(int idx) {
    if(idx == n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] <= 0) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }
    if(s[idx] <= 0) func(idx+1);
    else {
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(idx == i) continue; // 손에 든 계란은 칠 수 없다
            if(s[i] <=  0) continue; // 치려는 계란이 깨져있음
            s[idx] -= w[i];
            s[i] -= w[idx];
            flag = true;
            func(idx+1);
            s[i] += w[idx];
            s[idx] += w[i];
        }
        if(!flag) func(n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }
    func(0);
    cout << answer;
}