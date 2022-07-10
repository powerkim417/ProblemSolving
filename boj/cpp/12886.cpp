#include <iostream>

using namespace std;

// 돌 합이 최대 1500이므로 배열 범위도 1500까지 담을 수 있도록 해야 함
// 1500^3 은 메모리 초과.. 어차피 a+b+c가 일정하므로 2차원으로도 할 수 있음
bool visited[1501][1501] = {};
int sum;

bool dfs(int a, int b, int c){
    bool ret = false;
    visited[a][b] = true;
    if (a==b && b==c) return true;
    // a-b
    if ((a>b) && !visited[a-b][b+b]) ret |= dfs(a-b, b+b, c);
    if ((a<b) && !visited[a+a][b-a]) ret |= dfs(a+a, b-a, c);
    // b-c
    if ((b>c) && !visited[a][b-c]) ret |= dfs(a, b-c, c+c);
    if ((b<c) && !visited[a][b+b]) ret |= dfs(a, b+b, c-b);
    // c-a
    if ((c>a) && !visited[a+a][b]) ret |= dfs(a+a, b, c-a);
    if ((c<a) && !visited[a-c][b]) ret |= dfs(a-c, b, c+c);
    return ret;
}

int main(void){
    int a, b, c;
    cin>>a>>b>>c;
    sum = a+b+c;
    if (sum%3 != 0) cout<<"0";
    else cout<<dfs(a, b, c);
    return 0;
}