#include <iostream>
#include <queue>

using namespace std;

int n;
int map[16][16];

struct pipe {
    int r; // 앞부분의 좌표
    int c;
    int d; // 0ㅡ가로 1|세로 2\대각선
};

int ans = 0;

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

// 우 또는 하로만 가므로 visited 체크는 필요 없음
void bfs(){
    queue<pipe> q;
    q.push({0, 1, 0});
    while (!q.empty()){
        pipe cur = q.front();
        q.pop();
        if (cur.r == n-1 && cur.c == n-1) ans++;
        switch (cur.d){
            case 0:
            if (isRange(cur.r, cur.c+1)
            && map[cur.r][cur.c+1]==0)
                q.push({cur.r, cur.c+1, 0});
            if (isRange(cur.r+1, cur.c+1)
            && map[cur.r+1][cur.c]==0
            && map[cur.r][cur.c+1]==0
            && map[cur.r+1][cur.c+1]==0)
                q.push({cur.r+1, cur.c+1, 2});
            break;
            case 1:
            if (isRange(cur.r+1, cur.c)
            && map[cur.r+1][cur.c]==0)
                q.push({cur.r+1, cur.c, 1});
            if (isRange(cur.r+1, cur.c+1)
            && map[cur.r+1][cur.c]==0
            && map[cur.r][cur.c+1]==0
            && map[cur.r+1][cur.c+1]==0)
                q.push({cur.r+1, cur.c+1, 2});
            break;
            case 2:
            if (isRange(cur.r, cur.c+1)
            && map[cur.r][cur.c+1]==0)
                q.push({cur.r, cur.c+1, 0});
            if (isRange(cur.r+1, cur.c)
            && map[cur.r+1][cur.c]==0)
                q.push({cur.r+1, cur.c, 1});
            if (isRange(cur.r+1, cur.c+1)
            && map[cur.r+1][cur.c]==0
            && map[cur.r][cur.c+1]==0
            && map[cur.r+1][cur.c+1]==0)
                q.push({cur.r+1, cur.c+1, 2});
            break;
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    bfs();
    cout<<ans;
    return 0;
}