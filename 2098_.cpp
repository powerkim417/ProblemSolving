#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int cost[n][n];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>cost[i][j];
        }
    }
    // 순회 여행 경로이므로 첫번째 마을을 시작점으로 잡아도 됨
}