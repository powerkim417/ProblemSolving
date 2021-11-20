#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = -1;
int arr[8];
bool visited[8] = {};
vector<int> perm;

int abs(int x) {return (x>0)?x:-x;}

void calculate(){
    int temp = 0;
    // cout<<perm[0];
    for (int i=1 ; i<n ; i++){
        // cout<<" "<<perm[i];
        temp += abs(perm[i]-perm[i-1]);
    }
    // cout<<"\n";
    if (temp > answer) answer = temp;
    return;
}

// DFS 순열 백트래킹
void dfs(int depth){
    if (depth == n){
        calculate();
    }
    for (int next=0 ; next<n ; next++){
        if (visited[next]) continue;
        visited[next] = true;
        perm.push_back(arr[next]);
        dfs(depth+1);
        visited[next] = false;
        perm.pop_back();
    }
}

// n<=8 이므로 모든 경우의 수에 대해 다 해보면 됨
// next permutation으로는 쉬우니 백트래킹으로 구현
int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    dfs(0);
    cout<<answer;
    return 0;
}