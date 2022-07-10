#include <iostream>
#include <vector>

using namespace std;

bool visited[10001];
vector<int> adj[10001];
int cnt;

void dfs(int x){
    visited[x] = true;
    for (int next: adj[x]){
        if (!visited[next]){
            dfs(next);
            cnt++;
        }
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    int a,b;
    for (int t=0 ; t<m ; t++){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    int max = 0;
    vector<int> answers;
    for (int i=1 ; i<=n ; i++){
        cnt = 0;
        for (int j=1 ; j<=n ; j++) visited[j] = false;
        dfs(i);
        if (max < cnt){
            max = cnt;
            answers.clear();
            answers.push_back(i);
        }
        else if (max == cnt){
            answers.push_back(i);
        }
    }
    int answers_size = answers.size();
    for (int i=0 ; i<answers_size; i++){
        cout<<answers[i]<<" ";
    }
}
