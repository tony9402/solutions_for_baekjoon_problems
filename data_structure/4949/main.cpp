// Authored by : jminryu
// Co-authored by : -
// Link : http://boj.kr/1f1b7257c19e45169d3c4384b315ec7f
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    while (1) {
        getline(cin, str);
        if (str == ".") break;
        
        bool isBalanced = true;
        stack<char> st;
        
        for (char c : str) {
            if (!isBalanced) break;
            switch (c) {
                case '(':
                    st.push(c);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') isBalanced = false;
                    else st.pop();
                    break;
                case '[':
                    st.push(c);
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') isBalanced = false;
                    else st.pop();
                    break;
                default:
                    break;
            }
        }
        if (isBalanced && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
