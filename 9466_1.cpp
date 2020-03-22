#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int pick[100001]; // i가 선택한 사람
int visited[100001] = {}; // i를 방문한 때의 시각(큰 dfs 하나 시작시마다 바뀜)
int cycle;
int time; // 매 방문마다 1씩 늘어남
int start_time; // 매 메인 DFS 시작 시간

// DFS 사이클 찾기의 가장 기본 문제 형태. 잘 숙지할 것
// 스택을 안 쓴 남규의 풀이. 이렇게 공부할것!!!!!

void dfs(int cur){
    // cout<<cur<<"\n";
    visited[cur] = time++;
    int next = pick[cur];
    if (visited[next] == 0) { // 아직 방문하지 않은 경우
        dfs(next);
    }
    else if (visited[next] >= start_time){ // 현재 DFS에서 이미 방문했던 점. 즉, cycle의 반복점을 처음 찾음
        cycle += time - visited[next];
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int tc=0 ; tc<t ; tc++){
        cin>>n;
        cycle = 0;
        time = 0;
        for (int i=1 ; i<=n ; i++){
            cin>>pick[i];
            visited[i] = 0;
        }
        for (int i=1 ; i<=n ; i++){
            if (visited[i] == 0) { // visited가 기록된 애들은 기존에 dfs 탐색으로 이미 확인하였고,
            //사이클이 맞거나(자신에게 돌아왔거나) 사이클에 속하지 않는(자신에게 돌아오지 않은) 둘중 하나로 이미 판별이 난 뒤이므로 더 볼 필요 없음
                // cout<<"---DFS of "<<i<<" start---\n";
                start_time = time;
                dfs(i);
            }
        }
        cout<<(n-cycle)<<"\n";
    }
    return 0;
}