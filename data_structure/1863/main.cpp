// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/4b2a357a672a49aa8554582ea6076ee2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, x, y, ans = 0;
    stack<int> st;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        
        if (st.empty() && y != 0) {
            st.push(y); 
            continue;
        }
        
        while (!st.empty()) {
            if (st.top() < y) break;
            else if (st.top() == y) {
                st.pop(); 
                break;
            } else {
                st.pop(); 
                ans++;
            }
        }
        
        if (y != 0) st.push(y);
    }
    
    while (!st.empty()) {
    	ans++;
    	st.pop();
    }
    
    cout << ans;
    
    return 0;
}