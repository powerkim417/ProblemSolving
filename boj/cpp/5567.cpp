#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501] = {};
bool invite[501] = {};
int main(void){
    int n, m;
    cin>>n>>m;
    int a,b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int friends = adj[1].size();
    for (int i=0 ; i<friends ; i++){
        invite[adj[1][i]] = true;
    }
    for (int f: adj[1]){
        for (int ff: adj[f]){
            invite[ff] = true;
        }
    }
    int answer = 0;
    for (int i=2 ; i<=500 ; i++){
        if (invite[i]) answer++;
    }
    cout<<answer;
}