#include <iostream>

using namespace std;

int map[20][20];
int n, m, x, y;

struct dice {
    int up;
    int down;
    int right;
    int left;
    int front;
    int back;
};

dice cur = {0, 0, 0, 0, 0, 0};

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

bool isRange(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void move(int num){
    int nx = x+dr[num];
    int ny = y+dc[num];
    if (!isRange(nx, ny)) return;

    x = nx;
    y = ny;

    if (num == 0){ // 동
        cur = {cur.left, cur.right, cur.up, cur.down, cur.front, cur.back};
    }
    if (num == 1){ // 서
        cur = {cur.right, cur.left, cur.down, cur.up, cur.front, cur.back};
    }
    if (num == 2){ // 북
        cur = {cur.front, cur.back, cur.right, cur.left, cur.down, cur.up};
    }
    if (num == 3){ // 남
        cur = {cur.back, cur.front, cur.right, cur.left, cur.up, cur.down};
    }
    if (map[x][y]==0) map[x][y] = cur.down;
    else {
        cur.down = map[x][y];
        map[x][y] = 0;
    }
    cout<<cur.up<<"\n";
}

int main(void){
    int k;
    cin>>n>>m>>x>>y>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    int num;
    for (int i=0 ; i<k ; i++){
        cin>>num;
        move(num-1);
    }
}