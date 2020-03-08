#include <iostream>

using namespace std;

int n, m;
int map[300][300];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[300][300];

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

int nearSeaCnt(int i, int j){
    int ret = 0;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (!isRange(ni, nj)) continue;
        if (map[ni][nj]==0) ret++;
    }
    return ret;
}

int melt(){
    int ret = 0;
    int newmap[300][300];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            newmap[i][j] = map[i][j] - nearSeaCnt(i, j);
            if (newmap[i][j]<0) newmap[i][j] = 0;
            ret += map[i][j]-newmap[i][j];
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            map[i][j] = newmap[i][j];
        }
    }
    return ret; // 한번 녹았을 때 총 빙산의 변화량 반환
}

int total(){
    int ret;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            ret += map[i][j];
        }
    }
    return ret;
}

void dfs(int i, int j){
    visited[i][j] = true;
    int ni, nj;
    for (int d=0 ; d<4 ; d++){
        ni = i + dr[d];
        nj = j + dc[d];
        if (map[ni][nj]!=0 && !visited[ni][nj]) dfs(ni, nj);
    }
}

/* 구현
1. (해결)칸을 하나씩 갱신하면 다른 칸에 영향을 미치므로 한번에 바꿔야 함
*/
/* 예외
1. 전부 녹을 때까지 두덩어리 이상으로 분리되지 않음
2. (해결)바다가 없어서 녹지 않음
*/

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    int comp;
    int time = 0;
    while (1){
        // 전체 dfs로 컴포넌트 수 파악
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                visited[i][j] = false;
            }
        }
        comp = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j] != 0 && !visited[i][j]) {
                    comp++;
                    dfs(i, j);
                }
            }
        }
        if (comp >= 2) {
            cout<<time;
            return 0;
        }
        // 빙산 줄어듦
        time++;
        if (melt()==0){ // 변화 없을 때(사실 여기는 문제에서 명시 안함)
            cout<<"0";
            return 0;
        }
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (total()==0){ // 다 녹았는데 comp>=2가 안되고 여기까지 온 경우
            cout<<"0";
            return 0;
        }
    }
    return 0;
}