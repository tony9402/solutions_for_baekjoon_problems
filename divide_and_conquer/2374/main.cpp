// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/7936d1fc15f944b383baa0673547aa3f
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    stack<int> st;
    long long ans = 0;
    int n, mx = 0; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        
        if (st.empty()) {
            st.push(cur);
            mx = cur;
            continue;
        }
        
        if (st.top() < cur) {
            int top = st.top(); st.pop();
            mx = max(mx, cur);
            ans += (cur - top);
            st.push(cur);
        } else if (st.top() > cur) {
            st.pop(); st.push(cur);
        }
    }
    
    while(!st.empty()) {
        int top = st.top(); st.pop();
        ans += (mx - top);
    }
    
    cout << ans;
}