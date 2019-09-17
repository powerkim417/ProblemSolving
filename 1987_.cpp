#include <iostream>

using namespace std;

int r,c;
char map[20][20];

bool used[26];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int i, int j){
    if (i>=0 && i<r && j>=0 && j<c) return true;
    else return false;
}

void dfs(int i, int j){
    // cout<<i<<" "<<j<<endl;
    used[map[i][j]-'A'] = true;
    int temp = 0;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (inRange(ni, nj) && !used[map[ni][nj]-'A']){
            temp++;
            dfs(ni, nj);
        }
    }
    if (temp == 0)
        used[map[i][j]-'A'] = false;
}

int main(void){
    cin>>r>>c;
    for (int i=0 ; i<26 ; i++) used[i] = false;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>map[i][j];
        }
    }
    dfs(0,0);
    int cnt = 0;
    for (int i=0 ; i<26 ; i++) {
        if (used[i]) cnt++;
    }
    cout<<(cnt+1);
}