#include <iostream>

using namespace std;

// 우상 부터 왼쪽으로 45도
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {1, 0, -1, -1, -1, 0, 1, 1};

struct Fish {
    int r;
    int c;
    int d;
};

bool isRange(int i, int j){
    return (i>=0 && i<4 && j>=0 && j<4);
}

Fish fish[17];
int map[4][4]; // 1~16: 물고기, 0: 빈칸, -1: 상어
int answer = 0;

void swap(Fish& a, Fish& b){
    Fish temp = a;
    a = b;
    b = temp;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void dfs(Fish cur_shark, int sum){
    if (sum > answer) answer = sum;
    // 번호가 작은 물고기부터 순서대로 이동
    int dcnt;
    for (int i=1 ; i<=16 ; i++){
        dcnt = 0;
        Fish& cur = fish[i];
        int nr = cur.r + dr[cur.d];
        int nc = cur.c + dc[cur.d];
        while (dcnt < 8){
            if (isRange(nr, nc)){
                if (map[nr][nc]==0){ // 빈칸
                    map[nr][nc] = i;
                    cur.r = nr;
                    cur.c = nc;
                }
                else if (map[nr][nc]!=-1){ // 다른 물고기
                    swap(fish[i], fish[map[nr][nc]]);
                    swap(i, map[nr][nc]);
                }
            }
            else { // 범위 밖이거나, 상어
                cur.d = (cur.d+1)%8;
                dcnt++;
            }
        }
    }

    // 상어의 이동
    for (int i=1 ; i<=3 ; i++){ // 최대 3개까지 가능
        int nr = cur_shark.r + i*dr[cur_shark.d];
        int nc = cur_shark.c + i*dc[cur_shark.d];
        if (isRange(nr, nc) && map[nr][nc]!=0) { // 새 위치에 물고기가 있는 경우
            int fish_num = map[nr][nc];
            map[cur_shark.r][cur_shark.c] = 0;
            map[nr][nc] = -1;
            dfs({nr, nc, fish[fish_num].d}, sum+fish_num);
            map[cur_shark.r][cur_shark.c] = -1;
            map[nr][nc] = fish_num;
        }
    }
}

int main(void){
    int a,b;
    Fish shark = {-1, -1, -1};
    for (int i=0 ; i<4 ; i++){
        for (int j=0 ; j<4 ; j++){
            cin>>a>>b;
            fish[a] = {i, j, b%8};
            map[i][j] = a;
            if (i==0 && j==0) {
                swap(shark, fish[a]);
                map[i][j] = -1;
            }
        }
    }
    // for (int i=1 ; i<=16 ; i++){
    //     cout<<fish[i].r<<" "<<fish[i].c<<" "<<fish[i].d<<"\n";
    // }

    dfs(shark, a);

    cout<<answer;
    return 0;
}