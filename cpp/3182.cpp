#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool visited[1001] = {};
int cnt;

void dfs(int cur){
    cnt++;
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main(void){
    int n;
    cin>>n;
    int temp;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        adj[i].push_back(temp);
    }
    int max = 0;
    int max_senior = 1;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++) visited[j] = false; // 방문 배열 초기화
        cnt = 0;
        dfs(i);
        if (max < cnt) { // 최대값이 같을 때는 번호가 작은 선배를 저장해야 하므로 최대값보다 클 때만 갱신
            max = cnt;
            max_senior = i; 
        }
    }
    cout<<max_senior;
}