#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[50][50];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool visited[50][50][4][2][2] = {}; // r, c, 방향, C방문 여부, c방문 여부(2개를 각각 다르게 봐야 함)

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

struct state {
    int r;
    int c;
    int d; // 우 하 좌 상, 다음에 갈 방향
    bool Cv;
    bool cv;
    int time;
};

int bfs(int sr, int sc){
    queue<state> q;
    for (int d=0 ; d<4 ; d++){
        q.push({sr, sc, d, false, false, 0});
        visited[sr][sc][d][0][0] = true;
    }
    while (!q.empty()){
        state cur = q.front();
        // cout<<cur.r<<" "<<cur.c<<" "<<cur.d<<" "<<cur.Cv<<" "<<cur.cv<<" "<<cur.time<<"\n";
        q.pop();

        if (cur.Cv && cur.cv) return cur.time;
        
        // 다음 좌표는 cur.d에 의해 정해짐
        int nr = cur.r + dr[cur.d];
        int nc = cur.c + dc[cur.d];
        if (!isRange(nr, nc)) continue;
        if (map[nr][nc]=='#') continue;
        bool nCv = cur.Cv | (map[nr][nc]=='C');
        bool ncv = cur.cv | (map[nr][nc]=='c');

        // (nr, nc)가 적합한 경우 나머지 3개의 nd를 queue에 넣음
        for (int nd=0 ; nd<4 ; nd++){
            if (nd==cur.d) continue;
            if (visited[nr][nc][nd][nCv][ncv]) continue;
            visited[nr][nc][nd][nCv][ncv] = true;
            q.push({nr, nc, nd, nCv, ncv, cur.time+1});
        }
    }
    return -1;
}

int main(void){
    cin>>n>>m;
    int sr = -1, sc = -1;
    bool flag = false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]=='S'){
                sr = i;
                sc = j;
            }
            if (map[i][j]=='C'){
                if (flag) map[i][j] = 'c'; // 두번째 C는 c로 바꿈
                else flag = true;
            }
        }
    }
    cout<<bfs(sr, sc);
    return 0;
}