#include <iostream>
#include <vector>
#include <bitset>
#define INF 1000+1

using namespace std;

int n;
int pop[10];
vector<int> adj[10];
bool visited[10];
int answer = INF;

bool check(int n, int bit){
    return (bit>>n)%2;
}

void dfs(int cur, int area, int bit){
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next] && check(next, bit) == area) dfs(next, area, bit);
    }
}

int abs(int x){
    return (x>0)?x:-x;
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>pop[i];
    }
    int a, temp;
    for (int i=0 ; i<n ; i++){
        cin>>a;
        for (int j=0 ; j<a ; j++){
            cin>>temp;
            adj[i].push_back(temp-1);
        }
    }
    // 0..01 ~ 1..10(n자리, 최대 1022가지) 까지의 수를 이용해 각각 선거구가 나뉘는 모든 경우 확인
    for (int i=1 ; i<=(1<<n)-2 ; i++){
        int zero, one;
        for (int j=0 ; j<n ; j++){
            if ((i>>j)%2==0) zero = j;
            else one = j;
        }
        /*
        이렇게 하고나면 zero는 0구역에 속하는 가장 큰 자릿수,
        one은 1구역에 속하는 가장 작은 자릿수를 할당받게 된다.
        */

        /*
        zero에서 시작해서 0구역만 지나는 dfs를 하고,
        one에서 시작해서 1구역만 지나닌 dfs를 했을 때
        모든 구역이 다 방문되어 있어야 한다.
        */
        for (int j=0 ; j<n ; j++){
            visited[j] = false;
        }
        dfs(zero, 0, i);
        dfs(one, 1, i);
        bool flag = true;
        for (int j=0 ; j<n ; j++){
            if (!visited[j]) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        // 선거구 구역 나누기 조건을 만족함
        // bitset<10> x(i);
        // cout<<x<<"\n";
        int zero_pop = 0;
        int one_pop = 0;
        for (int j=0 ; j<n ; j++){
            if (check(j, i)==1) one_pop += pop[j];
            else zero_pop += pop[j];
        }
        int temp = abs(one_pop-zero_pop);
        if (temp < answer) answer = temp;
    }
    if (answer == INF) cout<<"-1";
    else cout<<answer;
    return 0;
}