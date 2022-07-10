#include <iostream>
#include <queue>

using namespace std;

bool visited[200][200][31] = {}; // (i, j)를 능력이 k만큼 남았을 때 방문했는지 여부
int k, w, h;
int map[200][200];

// 0~3: 능력 필요 X / 4~11: 능력 소모
int dr[12] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
int dc[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};

bool isRange(int r, int c){
    return (r>=0 && r<h && c>=0 && c<w);
}

struct state {
    int r;
    int c;
    int power;
    int time;
};

/* BFS를 깔끔하게 짜는 두가지 팁!
1. bfs에 해당하는 부분을 따로 함수로 분리
2. time = 0, time++ 로 시간 관리하는 대신
넘겨주는 struct에 time이나 cost를 넣고 cur에서 열어봤을 때 비교할 것
*/
int bfs(){
    queue<state> q;
    q.push({0, 0, k, 0});
    visited[0][0][k] = true;
    while (!q.empty()){
        state cur = q.front();
        // cout<<cur.r<<" "<<cur.c<<" "<<cur.power<<" "<<cur.time<<"\n";
        if (cur.r == h-1 && cur.c == w-1){
            return cur.time;
        }
        q.pop();
        for (int d=0 ; d<12 ; d++){
            if (d==4 && cur.power == 0) break;
            // 능력이 필요없는 d=0~3은 다 보고, 능력이 필요한 4부터는 power가 없을 경우 반복문 종료되므로
            // d=4 이상일 때는 power가 1 이상인 경우만 들어옴이 보장됨
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            int np = cur.power + ((d>=4)?(-1):0);
            if (isRange(nr, nc) && map[nr][nc]==0 && !visited[nr][nc][np]){
                visited[nr][nc][np] = true;
                q.push({nr, nc, np, cur.time+1});
            }
        }
    }
    return -1;
}

int main(void){
    cin>>k>>w>>h;
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<w ; j++){
            cin>>map[i][j];
        }
    }
    cout<<bfs();
    return 0;
}