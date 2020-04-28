#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n,m,k;
typedef pair<int, int> edge;
vector<edge> adj[1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    int a,b,c;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
}