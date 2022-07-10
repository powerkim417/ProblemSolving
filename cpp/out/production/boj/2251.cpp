#include <iostream>

using namespace std;

bool visited[201][201][201] = {};

int A,B,C;

void dfs(int a, int b, int c){
    visited[a][b][c] = true;
    // a->b
    if (a+b <= B && !visited[0][a+b][c]) dfs(0, a+b, c);
    else if (a+b > B && !visited[a+b-B][B][c]) dfs(a+b-B, B, c);
    // a->c
    if (a+c <= C && !visited[0][b][a+c]) dfs(0, b, a+c);
    else if (a+c > C && !visited[a+c-C][b][C]) dfs(a+c-C, b, C);
    // b->a
    if (b+a <= A && !visited[b+a][0][c]) dfs(b+a, 0, c);
    else if (b+a > A && !visited[A][b+a-A][c]) dfs(A, b+a-A, c);
    // b->c
    if (b+c <= C && !visited[a][0][b+c]) dfs(a, 0, b+c);
    else if (b+c > C && !visited[a][b+c-C][C]) dfs(a, b+c-C, C);
    // c->a
    if (c+a <= A && !visited[c+a][b][0]) dfs(c+a, b, 0);
    else if (c+a > A && !visited[A][b][c+a-A]) dfs(A, b, c+a-A);
    // c->b
    if (c+b <= B && !visited[a][c+b][0]) dfs(a, c+b, 0);
    else if (c+b > B && !visited[a][B][c+b-B]) dfs(a, B, c+b-B);
}

int main(void){
    cin>>A>>B>>C;
    dfs(0,0,C);
    for (int cc=0 ; cc<=200 ; cc++){
        for (int bb=0 ; bb<=200 ; bb++){
            if (visited[0][bb][cc]){
                cout<<cc<<" ";
                break;
            }
        }
    }
    return 0;
}