#include <iostream>

using namespace std;

// N-queen에서 방문 체크를 하는 일반적인 방법
int mark[15] = {}; // i번째 행에서 어느 열에 있는지

int n;
int cnt = 0;

int abs(int x){
    return (x>0)?x:(-x);
}

void dfs(int i, int j){ // i열에서 j행에 넣는다.
    mark[i] = j;
    if (i==n-1){
        cnt++;
        return;
    }
    bool able = true;
    for (int nj=0 ; nj<n ; nj++){ // (i+1, nj)를 방문하려 하는데,
        able = true;
        for (int oi=0 ; oi<=i ; oi++){ // 이전 점 (oi,mark[oi])와 비교
            if (mark[oi]==nj || abs(i+1-oi)==abs(nj-mark[oi])){
                able = false;
                break;
            }
        }
        // 이전 점들과의 검증을 모두 통과
        if (able) dfs(i+1, nj);
    }
    // 백트래킹의 일환으로 미방문 상태로 전환해야 하는 것은
    // 검증 과정에서 oi가 i 이전까지만 보기 때문에 굳이 돌려놓을 필요가 없음
}

// N-Queen
// N^2개의 위치가 있고, 이 중 N개를 택해야 하는 문제.
// 지금까지 고른 좌표들과 x축, y축, 대각선 모두 겹치면 안됨

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++) mark[i] = -1;
    for (int j=0 ; j<n ; j++){
        dfs(0, j); // 0번째 행의 각각 0~n-1번째 열에서 시작
    }
    cout<<cnt;
    return 0;
}