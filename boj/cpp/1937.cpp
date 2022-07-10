#include <iostream>
#include <algorithm>

using namespace std;

int dp[500][500]; // 특정 위치에서 가장 멀리 갈 수 있는 거리
int mov_r[4] = {-1, 0, 1, 0};
int mov_c[4] = {0, 1, 0, -1};
int n;
int map[500][500];

bool inRange(int r, int c){
    if (r>=0 && r<n && c>=0 && c<n) return true;
    else return false;
}

int farest(int r, int c){
    int& ret = dp[r][c];
    if (ret != -1) return ret;
    ret = 1; // 일단 내리면 1일은 살 수 있음
    for (int i=0 ; i<4 ; i++){
        int newr = r+mov_r[i];
        int newc = c+mov_c[i];
        if (inRange(newr, newc) && (map[newr][newc] > map[r][c])){
            ret = max(ret, farest(newr, newc) + 1);
            // 다음 위치가 갈 수 있는 위치라면
            // 해당 위치에서보다 하루 더 살 수 있으므로
            // 해당 위치의 dp값보다 1이 더 큰 값을 갖게 된다.
            // 이렇게 나오는 최대 4가지 값중 가장 큰 값을 부여!
            
            // !!기억할 것!! max는 중간중간 갱신이 아니고
            // 가능한 경우중 가장 큰 값을 취한 뒤 다음 과정부터는 고정이다!!

            /* 16064(Coolest Ski Route)와 같은 문제로, 16064를 먼저 풀고
            본 문제로 오니 훨씬 이해가 깔끔하다! */
        }
    }
    return ret;
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            dp[i][j] = -1;
            cin>>map[i][j];
        }
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            answer = max(answer, farest(i,j));
        }
    }
    cout<<answer;
}