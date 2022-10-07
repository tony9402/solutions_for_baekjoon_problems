// Authored by : tony9402
// Co-authored by : -
// Link : http://boj.kr/f5411b38217d48918c1e3222dfd33b5a
#include<bits/stdc++.h>

using namespace std;

int N, M;
char Map[30001][31];
vector<pair<int, int>> path[31];
// path[index] : index에서 돌을 던졌을 때 이동한 경로 (x, y)

void update(int idx) {
    // 저장된 경로에 돌이 있다면 해당 경로는 제거
    while(path[idx].size() > 1) {
        pair<int, int> pos = path[idx].back();
        if(Map[pos.first][pos.second] == '.') break;
        path[idx].pop_back();
    }

    // 돌이 미끄러질 수 있는 곳까지 경로 업데이트
    pair<int, int> curPos = path[idx].back();
    while(curPos.first + 1 < N) {
        // 돌 아래가 벽으로 막혀있는 경우 -> 멈춘다.
        if(Map[curPos.first + 1][curPos.second] == 'X') break;
        // 돌 아래가 비어있는 경우
        if(Map[curPos.first + 1][curPos.second] == '.') {
            ++curPos.first;
            path[idx].push_back(curPos);
        }
        // 돌 아래에 돌이 있는 경우
        else {
            // 돌의 왼쪽 칸과 왼쪽-아래 칸이 비어 있는 경우 -> 왼쪽-아래으로 이동
            if(curPos.second - 1 >= 0 && Map[curPos.first][curPos.second - 1] == '.' && Map[curPos.first + 1][curPos.second - 1] == '.') {
                ++curPos.first; --curPos.second;
                path[idx].push_back(curPos);
            }
            // 돌이 왼쪽으로 미끄러지지 않았고, 오른쪽 칸과 오른쪽-아래 칸이 비어 있는 경우 -> 오른쪽으로 이동
            else if(curPos.second + 1 < M && Map[curPos.first][curPos.second + 1] == '.' && Map[curPos.first + 1][curPos.second + 1] == '.') {
                ++curPos.first; ++curPos.second;
                path[idx].push_back(curPos);
            }
            // 두 가지 경우가 아니라면 -> 멈춘다.
            else break;
        }
    }
    Map[curPos.first][curPos.second] = 'O';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) cin >> Map[i];
    for(int i = 0; i < M; ++i) path[i].push_back(make_pair(0, i));
    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i) {
        int x; cin >> x; 
        update(x - 1); // index 0부터 시작했기 때문에 x-1
    }
    for(int i = 0; i < N; ++i) cout << Map[i] << '\n';

    return 0;
}
