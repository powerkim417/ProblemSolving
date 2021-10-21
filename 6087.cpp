#include <iostream>
#include <queue>
#define INF 10001

using namespace std;

struct point {
    int r;
    int c;
    
    bool operator==(const point& that) const {
        return (r==that.r && c==that.c);
    }
};

struct state {
    point p;
    int dir;
    int cnt;
};

int w, h;
char map[100][100];
int visited[100][100]; // (i,j)를 방문하는 가장 적은 거울 갯수(3차원 배열이면 터짐)
point s, e;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool isRange(int i, int j){
    return (i>=0 && i<h && j>=0 && j<w);
}

// 0-1 BFS 목표 도달 처리 방법
// 문제점: 다음 방문 노드가 dist가 같은 경우도 있고 1 증가하는 경우도 있어서 만약 dist가 더 큰 노드가 먼저 발견될 경우 잘못된 값을 반환하게 됨
// 1. deque를 통해 next dist가 증가하지 않는 경우(0) push_front하고, next dist가 증가하는 경우(1) push_back 한다.
//      이렇게 하면 dist가 더 작은 경우가 항상 더 먼저 탐색됨
// 2. visited 값은 항상 최소값으로 갱신되므로 도착점에 도착했을 때 종료하지 말고, while문을 끝까지 다 돌린 다음에 visited[도착점] 값을 반환한다.
int zeroOneBfs(){
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<w ; j++){
            visited[i][j] = INF;
        }
    }
    queue<state> q;
    for (int d=0 ; d<4 ; d++){
        q.push({s, d, 0});
    }
    visited[s.r][s.c] = 0;
    while (!q.empty()){
        state cur = q.front();
        // cout<<cur.p.r<<" "<<cur.p.c<<" "<<cur.dir<<" "<<cur.cnt<<"\n";
        q.pop();
        for (int nd=0 ; nd<4 ; nd++){
            int nr = cur.p.r+dr[nd];
            int nc = cur.p.c+dc[nd];
            int ncnt = cur.cnt;
            if (nd!=cur.dir) ncnt++;
            if (isRange(nr, nc) && map[nr][nc]!='*' && visited[nr][nc]>=ncnt){
                visited[nr][nc] = ncnt;
                q.push({nr,nc,nd,ncnt});
            }
        }
    }
    return visited[e.r][e.c];
}

int main(void){
    cin>>w>>h;
    bool flag = false;
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<w ; j++){
            cin>>map[i][j];
            if (map[i][j]=='C'){
                if (!flag){
                    flag = true;
                    s = {i, j};
                }
                else e = {i, j};
            }
        }
    }
    cout<<zeroOneBfs();
    return 0;

}