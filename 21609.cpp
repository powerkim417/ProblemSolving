#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[20][20]; // 1~ 색깔 / 0 무지개 / -1 검정 / -2 빈칸
bool visited[20][20];

struct point {
    int r;
    int c;

    state operator>(const state& that){
        if (r != that.r) return r > that.r;
        else return c > that.c;
    }
};

struct state {
    int block_cnt;
    int rainbow_cnt;
    point p;

    state operator+(const state& that) {
        return {block_cnt+that.block_cnt,
         rainbow_cnt+that.rainbow_cnt,
         p>that.p ? p : that.p};
    }
};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void visit_clear(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            visited[i][j] = false;
        }
    }
}

state find_group(int i, int j){
    state ret = {1, map[i][j]==0};
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (!isRange(ni, nj)) continue;
        if (map[ni][nj]==map[i][j] || map[ni][nj]==0){
            ret += dfs(ni, nj);
        }
    }
    return ret;
}

void remove(int i, int j, int color){
    map[i][j] = -2;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (!isRange(ni, nj)) continue;
    }
}

void gravity(){

}

void rotate(){

}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
}