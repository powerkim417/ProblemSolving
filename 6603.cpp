// DFS 백트래킹 풀이
#include <iostream>
#include <vector>

using namespace std;

int k;
int num[12]; // 고르게 될 k개의 수
bool visited[12];

void print(vector<int> &v){
    int v_size = v.size();
    for (int i=0 ; i<v_size ; i++){
        cout<<num[v[i]]<<" ";
    }
    cout<<"\n";
    return;
}

// 6번 방문해야 함
void dfs(int cur, vector<int> &v){
    visited[cur] = true;
    v.push_back(cur);
    if (v.size()==6){
        print(v);
        // v를 재활용해야 하므로 한 테케 출력이 끝났을 때에도 마지막 원소 방문 해제를 해줘야 함
        v.pop_back();
        visited[cur] = false;
        return;
    }
    for (int i=cur+1 ; i<k ; i++){
        if (!visited[i]) {
            dfs(i, v);
        }
    }
    v.pop_back();
    visited[cur] = false;
}

vector<int> v;

int main(void){
    while (cin>>k){
        if (k==0) return 0;
        for (int i=0 ; i<k ; i++){
            cin>>num[i];
            visited[i] = false;
        }
        for (int i=0 ; i<k ; i++){
            if (!visited[i]) {
                v = vector<int>();
                dfs(i, v);
            }
        }
        cout<<"\n";
    }
}