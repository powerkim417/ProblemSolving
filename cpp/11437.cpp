#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 50000 + 1;
const int MAXLOGN = 15 + 1; // log_2(50001) = 15.61...
vector<int> adj[MAXN];
int par[MAXN][MAXLOGN]; 
int ts[MAXN][2]; // [노드 번호][0시작 1끝]
// bool visited[MAXN]; // 트리는 부모 또는 자식밖에 없으니 visited 필요 없음
int t=0;

// bfs로 짜면 스택 문제 적어서 빨리 채점될듯..!
void dfs(int x, int p){

    par[x][0] = p;
    for (int j=1 ; j<MAXLOGN ; j++){
        if (par[x][j-1] == -1) break; // 점프 올라가는게 넘어서는 경우
        par[x][j] = par[par[x][j-1]][j-1];
    }

    ts[x][0] = t++;

    for (int next: adj[x]){
        if (next == p) continue;
        dfs(next, x);
    }

    ts[x][1] = t++;
}

// a가 b의 조상일 경우
// as bs be ae
bool isInclude(int a, int b){
    if (ts[a][0]<=ts[b][0] && ts[b][1]<=ts[a][1]) return true;
    else return false;
}

int lca(int a, int b){
    if (isInclude(a, b)) return a;
    if (isInclude(b, a)) return b;

    // a 고정, b를 LCA 직전까지 올린다
    for (int i=MAXLOGN-1 ; i>=0 ; i--){
        if (par[b][i] != -1 && !isInclude(par[b][i], a)){
            // b에서 2^i만큼 올리는게 넘치는게 아니고, 그 올린 노드가 a의 조상이 아닐 때
            b = par[b][i];
        }
    }
    // 직전까지 올렸으니 이제 한칸 더 올리면 구하는 노드!
    return par[b][0];
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    int a,b;
    for (int i=0 ; i<MAXN ; i++){
        for (int j=0 ; j<MAXLOGN ; j++){
            par[i][j] = -1; // 초기화(-1은 부모가 없는 상태)
        }
    }
    for (int i=0 ; i<n-1 ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cin>>m;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
}