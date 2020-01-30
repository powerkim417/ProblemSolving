/* 
<벽 부수고 이동하기 3>
최대 k개의 벽까지 부술 수 있다
대신 이동할 때마다 낮밤이 바뀌는데, 낮에만 부수기 가능
제자리 유지 가능(1턴 소모)
*/
#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
char map[1000][1000];
bool visited[1000][1000][11]; // k: 방문할 때의 남은 능력의 갯수
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

// 제자리 추가
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int answer = -1;

struct point {
    int r;
    int c;
    int breakable;
};

queue<point> q;

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

void bfs(){
    q.push({0, 0, k});
    visited[0][0][k] = true;
    point cur;
    int dist = 1;
    // dist가 홀수일 때가 낮. 즉 dist가 홀수일 때만 부술 수 있음
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
                else if (dist%2==1 && !visited[newr][newc][cur.breakable-1] && cur.breakable > 0) { // 벽인데 부술 수 있는 경우
                    visited[newr][newc][cur.breakable-1] = true;
                    // cout<<"push1 "<<newr<<" "<<newc<<"\n";
                    q.push({newr, newc, cur.breakable-1});
                }
            }
            /* 제자리에 남는 경우
            다음 턴에 부수려고 남는 것이 전제이므로
            능력은 남아있어야 하며, 현재 밤일 경우에만 제자리를 다음에 추가함
            (무한루프 방지)
            */
            if (cur.breakable > 0 && dist%2==0) q.push(cur);
        }
        dist++;
    }
}

int main(void){
    cin>>n>>m>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            for (int temp=0 ; temp<k ; temp++){
                visited[i][j][temp] = false;
            }
        }
    }
    bfs();
    cout<<answer;
}