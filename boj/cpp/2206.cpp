/* 
<벽 부수고 이동하기 1>
최대 1개의 벽까지 부술 수 있다
*/
#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[1000][1000];
bool visited[1000][1000][2]; // k: 능력 있는 채로 방문한거면 1, 능력 없는 상태로 방문한거면 0
/*
4 4
0101
0101
0001
1110
이 경우 (2,2)를 능력이 있는 채로 방문할 수도 있고, 없는 채로 방문할 수 도 있는데
능력이 없는 채로 먼저 방문을 하게 되면 능력이 있는 채로 방문하는 경우가 visited에 의해 기록이 안됨.
그런데 이 맵을 뚫으려면 능력이 있는 채로 방문을 해야 하므로
능력이 있고/없고에 따라 방문 여부를 분리해야 함!
*/
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int answer = -1;

struct point {
    int r;
    int c;
    bool breakable;
};

queue<point> q;

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

void bfs(){
    q.push({0, 0, true});
    visited[0][0][1] = true;
    point cur;
    int dist = 1;
    int newr, newc;
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"---distance: "<<dist<<"---\n";
        for (int s=0 ; s<q_size ; s++){
            cur = q.front();
            // cout<<"cur: ("<<cur.r<<", "<<cur.c<<", "<<cur.breakable<<")\n";
            if (cur.r == n-1 && cur.c == m-1){
                answer = dist;
                return;
            }
            q.pop();
            for (int d=0 ; d<4 ; d++){
                newr = cur.r + dr[d];
                newc = cur.c + dc[d];
                // cout<<"new: "<<newr<<" "<<newc<<"\n";
                if (!isRange(newr, newc)) {
                    // cout<<"passed point: "<<newr<<" "<<newc<<"\n";
                    continue;
                }
                if (!visited[newr][newc][cur.breakable] && map[newr][newc]=='0') {
                    visited[newr][newc][cur.breakable] = true;
                    // cout<<"push0 "<<newr<<" "<<newc<<"\n";
                    q.push({newr, newc, cur.breakable});
                }
                else if (!visited[newr][newc][0] && cur.breakable) { // 벽인데 부술 수 있는 경우
                    visited[newr][newc][0] = true;
                    // cout<<"push1 "<<newr<<" "<<newc<<"\n";
                    q.push({newr, newc, false});
                }
            }
        }
        dist++;
    }
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            visited[i][j][0] = false;
            visited[i][j][1] = false;
            cin>>map[i][j];
        }
    }
    bfs();
    cout<<answer;
}