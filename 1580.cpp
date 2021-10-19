#include <iostream>
#include <queue>

using namespace std;

int n,m;

// (0, 0)을 추가함으로써 둘 중 하나만 움직이는 경우도 일반화할 수 있음
int dr[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

struct point {
    int r;
    int c;
    // struct 내 연산자 오버로딩
    bool operator==(const point& that) const {
        return (r==that.r && c==that.c);
    }

    bool operator!=(const point& that) const {
        return !(r==that.r && c==that.c);
    }
};

struct state {
    point A;
    point B;
    int cost;
};

char map[20][20];
bool visited[20][20][20][20] = {};
point sA, sB;

bool isRange(point p){
    return (p.r>=0 && p.r<n && p.c>=0 && p.c<m);
}

int bfs(){
    queue<state> q;
    q.push({sA, sB, 0});
    visited[sA.r][sA.c][sB.r][sB.c] = true;
    while (!q.empty()){
        state cur = q.front();
        q.pop();
        if (cur.A == sB && cur.B == sA){
            // cout<<cur.A.r<<" "<<cur.A.c<<" "<<cur.B.r<<" "<<cur.B.c<<"\n";
            return cur.cost;
        }
        for (int da=0 ; da<9 ; da++){
            point nA = {cur.A.r + dr[da], cur.A.c + dc[da]};
            for (int db=0 ; db<9 ; db++){
                point nB = {cur.B.r + dr[db], cur.B.c + dc[db]};
                if (!isRange(nA) || !isRange(nB) || nA == nB || (cur.A == nB && cur.B == nA)) continue;
                if (map[nA.r][nA.c] == '.' && map[nB.r][nB.c] == '.' && !visited[nA.r][nA.c][nB.r][nB.c]){
                    visited[nA.r][nA.c][nB.r][nB.c] = true;
                    q.push({nA, nB, cur.cost+1});
                }
            }
        }
    }
    return -1;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]=='A') {
                sA = {i, j};
                map[i][j] = '.';
            }
            if (map[i][j]=='B') {
                sB = {i, j};
                map[i][j] = '.';
            }
        }
    }
    cout<<bfs();
    return 0;
}