#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> adj[10001];
bool visited[10001];
int cnt;

void dfs(int cur){
    cnt++;
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next);
    }
}

vector<int> answers;
int max_cnt = -1;

int main(void){
    cin>>n>>m;
    int a,b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++) visited[j] = false;
        cnt = 0;
        dfs(i);
        if (max_cnt < cnt){
            answers.clear();
            answers.push_back(i);
            max_cnt = cnt;
        }
        else if (max_cnt == cnt){
            answers.push_back(i);
        }
    }
    int v_size = answers.size();
    for (int i=0 ; i<v_size ; i++){
        cout<<answers[i]<<" ";
    }
    return 0;
}