#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,k;
queue<int> q;
bool visited[100001] = {};
int prv[100001];

int bfs(){
    int time = 0;
    if (n==k) return time;
    q.push(n);
    visited[n] = true;
    while (!q.empty()){
        int q_size = q.size();
        while (q_size--){
            int cur = q.front();
            q.pop();
            if (cur-1>=0 && !visited[cur-1]){
                prv[cur-1] = cur;
                if (cur-1==k) return time+1;
                q.push(cur-1);
                visited[cur-1] = true;
            }
            if (cur+1<=100000 && !visited[cur+1]){
                prv[cur+1] = cur;
                if (cur+1==k) return time+1;
                q.push(cur+1);
                visited[cur+1] = true;
            }
            if (cur*2<=100000 && !visited[cur*2]){
                prv[cur*2] = cur;
                if (cur*2==k) return time+1;
                q.push(cur*2);
                visited[cur*2] = true;
            }
        }
        time++;
    }
}

int main(void){
    for (int i=0 ; i<=100000 ; i++) prv[i] = -1; // -1는 아직 기록되지 않은 상태
    cin>>n>>k;
    int answer = bfs();
    cout<<answer<<"\n";
    vector<int> v;
    v.push_back(k);
    int temp = k;
    for (int i=0 ; i<answer ; i++) {
        temp = prv[temp];
        v.push_back(temp);
    }
    int v_size = v.size();
    for (int i=v_size-1 ; i>=0 ; i--){
        cout<<v[i]<<" ";
    }
}