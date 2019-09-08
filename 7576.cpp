#include <iostream>
#include <queue>

using namespace std;

int m,n;
int map[1000][1000];
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

bool inRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

typedef pair<int, int> point;
queue<point> q;

int bfs(){
    /* queue에 시작 토마토들이 다 들어가 있다.
    보통은 1개의 시작점에서 BFS가 시작되지만
    이 경우 여러개의 시작점에서 동시에 BFS가 시작되는걸
    queue에 시작 토마토를 여러개를 넣음으로서
    동시에 여러 BFS가 진행되고, 이에 따른 depth까지 한번에 체크가 가능하게 됨! */

    // map[][]=0인 점만 탐색해서 1로 만들기 때문에 visited 배열이 따로 필요 없다.
    int ret = 0;
    while (!q.empty()){
        int q_size = q.size();
        for (int s=0 ; s<q_size ; s++){
            point cur = q.front();
            q.pop();
            for (int d=0 ; d<4 ; d++){
                if (inRange(cur.first+r[d], cur.second+c[d])
                && map[cur.first+r[d]][cur.second+c[d]] == 0){
                    q.push({cur.first+r[d], cur.second+c[d]});
                    map[cur.first+r[d]][cur.second+c[d]] = 1;
                }
            }
        }
        ret++;
    }
    ret--; // 하루 탐색이 끝나면 ret++ 되는 식인데,
           // 마지막날 탐색이 끝났을 때 그 ret값을 바로 출력해야 하나
           // ++이 된 다음에 반복문을 빠져나오므로
           // 마지막날까지 탐색이 끝났으면 ret에서 1을 다시 빼주고 반환해야
           // 원래대로의 날짜가 올바르게 출력된다.
    return ret;
}

int main(void){
    cin>>m>>n;
    // 1: 익은 토마토, 0: 익지않은 토마토, -1: 토마토 없는 칸
    // 토마토는 항상 익은 토마토가 옆에 있어야 익는다.

    int zero_cnt = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j] == 1) {
                q.push({i,j}); // 모든 시작토마토들을 큐에 넣고 시작!!(BFS의 시작점이 여러개가 되는 것!!)
                visited[i][j] = true;
            }
            else if (map[i][j] == 0) zero_cnt++;
        }
    }

    int answer = bfs();

    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    if (zero_cnt == 0) answer = 0;
    
    bool zero_flag = false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (map[i][j] == 0) {
                zero_flag = true;
                break;
            }
        }
        if (zero_flag) break;
    }

    if (zero_flag) answer = -1;

    cout<<answer;
}