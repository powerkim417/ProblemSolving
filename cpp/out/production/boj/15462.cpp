#include <iostream>
#include <vector>

using namespace std;

// 사이클을 찾는 문제
/*
1->3, 2->2, 3->1, 4->3의 경우
(1,3), (2)가 각각 사이클이 되어 아무리 턴이 많이 지나가도 계속 칸이 차있다.
하지만 사이클을 이루지 못한 4는 결국 소가 도달하지 못하는 순간이 오므로 해당 X.
즉 이 문제는 그래프에서 사이클을 이루는 노드의 수를 찾는 문제!
*/

int nn[100001]; // next node
int visited[100001];
int time = 0;
int cycle_nodes = 0;

void dfs(int cur, int comp_start_time){
    visited[cur] = time++;
    if (visited[nn[cur]]==-1) dfs(nn[cur], comp_start_time);
    else if (visited[nn[cur]] >= comp_start_time){ // 다음에 방문하려는 노드가 현재 루트 DFS에서 이미 방문한 노드인 경우
        cycle_nodes += time - visited[nn[cur]];
        // cout<<cycle_nodes<<"\n";
    }
    // 나머지 경우는 다음에 방문하려는 노드가 이미 방문된 상태고, cur는 미방문 상태이므로
    // next에서 cur로 가는 길이 없다는 것이다. 따라서 next와 cur는 한 사이클일 수 없다.
}

int main(void){
    int n;
    cin>>n;
    int temp;
    for (int i=1 ; i<=n ; i++){
        cin>>nn[i];
        visited[i] = -1;
    }
    for (int i=1 ; i<=n ; i++){
        if (visited[i]==-1) {
            dfs(i, time);
        }
    }
    cout<<cycle_nodes;
    return 0;
}