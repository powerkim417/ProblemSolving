#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int pick[100001]; // i가 선택한 사람
int visited[100001] = {}; // i를 방문한 때의 시각(큰 dfs 하나 시작시마다 바뀜)
int time;
int cycle;
stack<int> s;

// DFS 사이클 찾기의 가장 기본 문제 형태. 잘 숙지할 것

void dfs(int cur, stack<int> &s){ // 메모리 초과때문에 &s로 받는다.
    // cout<<cur<<"\n";
    visited[cur] = time;
    int next = pick[cur];
    if (visited[next] == 0) { // 아직 방문하지 않은 경우
        s.push(next);
        dfs(next, s);
    }
    else if (visited[next] == time){ // 현재 DFS에서 이미 방문했던 점. 즉, cycle의 반복점을 처음 찾음
        while (1) {
            cycle++;
            if (s.top() == next) break;
            s.pop();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int temp;
    for (int tc=0 ; tc<t ; tc++){
        cin>>n;
        time = 0;
        cycle = 0;
        for (int i=1 ; i<=n ; i++){
            cin>>pick[i];
            visited[i] = false;
        }
        for (int i=1 ; i<=n ; i++){
            if (visited[i] == 0) { // visited가 기록된 애들은 기존에 dfs 탐색으로 이미 확인하였고,
            //사이클이 맞거나(자신에게 돌아왔거나) 사이클에 속하지 않는(자신에게 돌아오지 않은) 둘중 하나로 이미 판별이 난 뒤이므로 더 볼 필요 없음
                time++;
                s = stack<int>();
                s.push(i);
                // cout<<"---DFS of "<<i<<" start---\n";
                dfs(i, s);
            }
        }
        cout<<(n-cycle)<<"\n";
    }
    return 0;
}