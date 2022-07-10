#include <iostream>
#include <vector>

using namespace std;

// 이걸 DFS로 풀도록 생각하는 것이 중요!!
// N개 중 (N+1)/2 번째가 되려면
// 자기보다 위 또는 아래인 구슬의 갯수가 (N+1)/2 - 1 = (N-1)/2 개를 넘어가면 안된다.

int n, m;
int lim;
vector<int> h_adj[100]; // i보다 무거운 구슬
vector<int> l_adj[100];
bool h_visited[100] = {};
bool l_visited[100] = {};
int heavier;
int lighter;

void h_dfs(int cur){
    h_visited[cur] = true;
    for (int next: h_adj[cur]){
        if (!h_visited[next]){
            heavier++; // 처음 구슬은 포함하면 안되므로 next 할 때부터 더해야 한다.
            h_visited[next] = true;
            h_dfs(next);
        }
    } 
}

void l_dfs(int cur){
    l_visited[cur] = true;
    for (int next: l_adj[cur]){
        if (!l_visited[next]){
            lighter++; // 처음 구슬은 포함하면 안되므로 next 할 때부터 더해야 한다.
            l_visited[next] = true;
            l_dfs(next);
        }
    }
}

int main(void){
    cin>>n>>m;
    lim = (n-1)/2; // 해당 구슬의 위 또는 아래에 있을 수 있는 구슬 수의 마지노선
    int a, b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        h_adj[b].push_back(a);
        l_adj[a].push_back(b);
    }
    int answer = 0;
    for (int i=1 ; i<=n ; i++){
        heavier = 0;
        lighter = 0;
        for (int j=1 ; j<=n ; j++){
            h_visited[j] = false;
            l_visited[j] = false;
        }
        h_dfs(i);
        l_dfs(i);
        // cout<<"----"<<i<<"----\n";
        // cout<<"heavier: "<<heavier<<"\n";
        // cout<<"lighter: "<<lighter<<"\n";
        if (heavier > lim || lighter > lim) {
            // cout<<i<<"\n";
            answer++;
        }
    }
    cout<<answer;
    return 0;
}