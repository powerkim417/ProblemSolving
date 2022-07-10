#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[100001];

int main(void){
    int n,k;
    cin>>n>>k;
    
    for (int i=0 ; i<=100000 ; i++){
        visited[i] = false;
    }
    // 인접노드: x-1, x+1, 2x
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int time = 0;
    bool finish = false;
    while (!q.empty()){
        int q_size = q.size();
        for (int s=0 ; s<q_size ; s++){
            int cur = q.front();
            // cout<<cur<<" ";
            if (cur == k) {
                finish = true;
                // cout<<"\nFOUND!!\n";
                break;
            }
            int adj[3] = {cur-1, cur+1, 2*cur};
            q.pop();
            for (int i=0 ; i<3 ; i++){
                if (adj[i]>=0 && adj[i]<=100000 && !visited[adj[i]]){
                    q.push(adj[i]);
                    visited[adj[i]] = true;
                }
            }
        }
        if (finish) break;
        time++;
        // cout<<"\n----- Time "<<time<<" finished -----\n";
    }
    cout<<time;
}