#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[20][20]; // 1~ 색깔 / 0 무지개 / -1 검정 / -2 빈칸
bool visited[20][20];

struct point {
    int r;
    int c;

    bool operator>(const point& that){
        if (r != that.r) return r > that.r;
        else return c > that.c;
    }
};

struct state {
    int block_cnt;
    int rainbow_cnt;
    point p;

    state operator+(const state& that) {
        point retp;
        if (map[that.p.r][that.p.c]==0) retp = p;
        else retp = p>that.p ? that.p : p;
        return {block_cnt+that.block_cnt,
         rainbow_cnt+that.rainbow_cnt,
         retp};
    }

    bool operator>(const state& that){
        if (block_cnt != that.block_cnt) return block_cnt > that.block_cnt;
        else if (rainbow_cnt != that.rainbow_cnt) return rainbow_cnt > that.rainbow_cnt;
        else return p > that.p;

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

state find_group(int i, int j, int color){
    state ret = {1, map[i][j]==0, {i, j}};
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (!isRange(ni, nj)) continue;
        if ((map[ni][nj]==color || map[ni][nj]==0) && !visited[ni][nj]){
            ret = ret + find_group(ni, nj, color);
        }
    }
    return ret;
}

void unvisit_rainbow(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j]==0) visited[i][j] = false;
        }
    }
}

void remove(int i, int j, int color){
    map[i][j] = -2;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (!isRange(ni, nj)) continue;
        if (map[ni][nj]==color || map[ni][nj]==0) remove(ni, nj, color);
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// !!!!!!!!!!!!!
void gravity(){
    for (int j=0 ; j<n ; j++){
        for (int i=n-2 ; i>=0 ; i--){ // i와 아래 블록간 스왑
            if (map[i][j]>=0 && map[i+1][j]==-2) {
                int dist = 0;
                while (map[i+dist+1][j]==-2){
                    swap(map[i+dist][j], map[i+dist+1][j]);
                    dist++;
                }
            }
        }
    }
}

// 90도 반시계
void rotate(){
    queue<int> q;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            q.push(map[i][j]);
        }
    }
    for (int j=0 ; j<n ; j++){
        for (int i=n-1 ; i>=0 ; i--){
            map[i][j] = q.front();
            q.pop();
        }
    }
}

void print(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j]==-2) cout<<"_ ";
            else if (map[i][j]==-1) cout<<"# ";
            else cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    int answer = 0;
    while (1){
        // 1
        // cout<<"[1]\n";
        state biggest = {-1, -1, {-1, -1}};
        visit_clear();
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (!visited[i][j] && map[i][j]>0) {
                    state temp = find_group(i, j, map[i][j]);
                    unvisit_rainbow();
                    if (temp > biggest) biggest = temp;
                }
            }
        }
        // cout<<biggest.block_cnt<<" "<<biggest.rainbow_cnt<<" "<<biggest.p.r<<" "<<biggest.p.c<<"\n";
        if (biggest.block_cnt < 2) break;
        // 2
        // cout<<"[2]\n";
        answer += biggest.block_cnt*biggest.block_cnt;
        remove(biggest.p.r, biggest.p.c, map[biggest.p.r][biggest.p.c]);
        // print();
        // 3
        // cout<<"[3]\n";
        gravity();
        // print();
        // 4
        // cout<<"[4]\n";
        rotate();
        // print();
        // 5
        // cout<<"[5]\n";
        gravity();
        // print();
    }
    cout<<answer;
    return 0;
}