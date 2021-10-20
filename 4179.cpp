#include <iostream>
#include <queue>

using namespace std;

int r, c;
char map[1000][1000];
int fire_visited[1000][1000];
bool visited[1000][1000] = {};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

struct point {
    int i;
    int j;
    
    bool operator==(const point& that) const {
        return (i==that.i && j==that.j);
    }

    bool operator!=(const point& that) const {
        return !(i==that.i && j==that.j);
    }
};

struct state {
    point p;
    int time;
};

bool isRange(int i, int j){
    return (i>=0 && i<r && j>=0 && j<c);
}

void fire_diffusion(vector<point>& fires){
    queue<state> q;
    for (auto fire: fires) {
        q.push({fire, 0});
        fire_visited[fire.i][fire.j] = 0;
    }
    while (!q.empty()){
        state cur = q.front();
        q.pop();
        for (int d=0 ; d<4 ; d++){
            int ni = cur.p.i + dr[d];
            int nj = cur.p.j + dc[d];
            if (isRange(ni, nj) && map[ni][nj]!='#' && fire_visited[ni][nj] == -1){
                fire_visited[ni][nj] = cur.time+1;
                q.push({{ni, nj}, cur.time+1});
            }
        }
    }
}

int escape(point man){
    queue<state> q;
    q.push({man, 0});
    visited[man.i][man.j] = true;
    while (!q.empty()){
        state cur = q.front();
        q.pop();
        for (int d=0 ; d<4 ; d++){
            int ni = cur.p.i + dr[d];
            int nj = cur.p.j + dc[d];
            if (!isRange(ni, nj)) return cur.time+1; // 여기가 일반적 bfs랑 다름
            if (map[ni][nj]!='#' && !visited[ni][nj] && (fire_visited[ni][nj]==-1 || cur.time+1 < fire_visited[ni][nj])){ // fv[][]==-1 인 곳도 방문해야 함
                visited[ni][nj] = true;
                q.push({{ni, nj}, cur.time+1});
            }
        }
    }
    return -1;
}

int main(void){
    cin>>r>>c;
    point man;
    vector<point> fires; // !!!!!!! 불이 여러 곳에서 나거나, 나지 않았을 수도 있으므로 불의 초기점은 vector로 저장해야 함
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            fire_visited[i][j] = -1;
            cin>>map[i][j];
            if (map[i][j]=='F') fires.push_back({i, j});
            else if (map[i][j]=='J') man = {i, j};
        }
    }
    fire_diffusion(fires);
    // for (int i=0 ; i<r ; i++){
    //     for (int j=0 ; j<c ; j++){
    //         cout<<fire_visited[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }   
    int answer = escape(man);
    if (answer == -1) cout<<"IMPOSSIBLE";
    else cout<<answer;
    return 0;
}