#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int a) {
    if (a<0) return -a;
    else return a;
}

vector<int> adj[2500];
bool visited[2500];
void dfs(int cur){
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next);
    }
}

int main(void){
    int t;
    cin>>t;
    for (int test=1 ; test<=t ; test++){
        int N,M,K;
        cin>>M>>N>>K;
        for (int i=0 ; i<2500 ; i++){
            adj[i].clear();
            visited[i] = false;
        }
        int x[K],y[K];
        for (int k=0 ; k<K ; k++){
            cin>>x[k]>>y[k];
        }
        for (int k1=0 ; k1<K ; k1++){
            for (int k2=0 ; k2<K ; k2++){
                if (abs(x[k1]-x[k2])+abs(y[k1]-y[k2])==1){
                    adj[k1].push_back(k2);
                    adj[k2].push_back(k1);
                }
            }
        }
        int comp = 0;
        for (int k=0 ; k<K ; k++){
            if (visited[k]==false){
                dfs(k);
                comp++;
            }
        }
        cout<<comp<<"\n";
    }
}