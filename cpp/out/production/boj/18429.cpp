#include <iostream>

using namespace std;

bool visited[9] = {};

int n, k;
int a[9];
int cnt = 0;

void dfs(int cur, int w, int day){
    // cout<<cur<<" "<<w<<" "<<day<<"\n";
    if (w+a[cur]-k<500) return; // 이 경우는 중량이 500 미만이 되었으므로 탐색 X. visit하지 않았다고 해야 한다.
    if (day == n) cnt++; // n일동안 운동하고도 살아남았으면 성공한 케이스니까 cnt++
    visited[cur] = true;
    for (int next=1 ; next<=n ; next++){
        if (next==cur) continue;
        if (!visited[next]) dfs(next, w+a[cur]-k, day+1);
    }
    visited[cur] = false;
    
}

int main(void){
    cin>>n>>k;
    for (int i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    for (int i=1 ; i<=n ; i++){
        // cout<<"-----\n";
        dfs(i, 500, 1); // 백트래킹으로 짜면 이거 하나 끝났을 때 다 false이므로 따로 초기화할 필요 없음
    }
    cout<<cnt;
    return 0;
}