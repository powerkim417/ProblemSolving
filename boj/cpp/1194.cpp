#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[50][50][64] = {}; // (i, j)를 key 상태 k로 방문한 여부

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

struct state {
    int r;
    int c;
    int key; // 000000 ~ 111111(64개), fedcba 순으로 기록
    int time;
};

void addkey(int& key, char cur){
    // cout<<"before: "<<key<<"\n";
    key |= (1<<(cur-'a'));
    // cout<<"after: "<<key<<"\n";
}

bool openable(int key, char cur){
    return (key & (1<<(cur-'a')));
}

int bfs(int sr, int sc){
    queue<state> q;
    q.push({sr, sc, 0, 0});
    visited[sr][sc][0] = true;

    while (!q.empty()){
        state cur = q.front();
        // cout<<cur.r<<" "<<cur.c<<" "<<cur.key<<" "<<cur.time<<"\n";
        q.pop();

        if (map[cur.r][cur.c] == '1') return cur.time;

        for (int d=0 ; d<4 ; d++){
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            int nkey = cur.key;
            if (!isRange(nr, nc) || map[nr][nc]=='#' || visited[nr][nc][nkey]) continue;
            if (map[nr][nc] >= 'a' && map[nr][nc] <= 'f') addkey(nkey, map[nr][nc]);
            else if (map[nr][nc] >= 'A' && map[nr][nc] <= 'F') {
                if (!openable(nkey, map[nr][nc])) continue;
            }
            q.push({nr, nc, nkey, cur.time+1});
            visited[nr][nc][nkey] = true;
        }
    }
    return -1;
}

int main(void){
    cin>>n>>m;
    int sr, sc;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]=='0'){
                sr = i;
                sc = j;
            }
        }
    }
    cout<<bfs(sr, sc);
    return 0;
}