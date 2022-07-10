#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
bool visited[51];
int del;
int leaf = 0;

void dfs(int idx, int parent){
    visited[idx] = true;
    int cnt = 0;
    for (int next: adj[idx]){
        if (next == parent) continue;
        if (next == del) continue; // 지우는 노드를 방문하려는 경우를 배제하면 노드를 지우는 효과를 얻을 수 있음
        if (!visited[next]) {
            dfs(next, idx);
            cnt++;
        }
    }
    if (cnt == 0) leaf++;
}

int main(void){
    int n;
    cin>>n;
    int p;
    int root;
    for (int i=0 ; i<n ; i++){
        visited[i] = false;
        cin>>p;
        if (p != -1) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        else {
            root = i;
        }
    }
    cin>>del;
    if (root == del) cout<<"0"; // 루트를 지우면 leaf가 다 사라짐
    else {
        dfs(root, -1);
        cout<<leaf;
    }
}