#include <iostream>

using namespace std;

int dist[99999];
int cost[100000];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=0 ; i<n-1 ; i++){
        cin>>dist[i];
    }
    for (int i=0 ; i<n ; i++){
        cin>>cost[i];
    }
    // 0->1까지 가는 길은 필수
    long long answer = 1LL*cost[0]*dist[0];
    int prev_cost = cost[0];
    for (int i=1 ; i<n-1 ; i++){
        // 현위치(i번째)에서 기름을 넣고 다음 거리로 가는게 더 적은지,
        // 지금까지 유지되고 있는 가장 싼 주유소에서 다음 거리만큼 기름을 넣었어야 하는게 더 적은지 비교
        // prev_cost는 특정 단계에서 갱신될 경우 갱신 전 값은 더 이상 못쓴다
        if (cost[i]<prev_cost) {
            answer += 1LL*cost[i]*dist[i];
            prev_cost = cost[i];
        }
        else {
            answer += 1LL*prev_cost*dist[i];
        }
        // 해당 연산이 끝나고 나면 i+1번째 위치까지 도달하는 모든 경우의 수 중 가장 적은 경우가 구해짐
    }
    cout<<answer;
    return 0;
}