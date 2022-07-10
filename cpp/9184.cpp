#include <iostream>

using namespace std;

int dp[21][21][21] = {};
bool visited[21][21][21] = {};

void dp_init(){
    for (int i=0 ; i<=20 ; i++){
        for (int j=0 ; j<=20 ; j++){
            for (int k=0 ; k<=20 ; k++){
                visited[i][j][k] = false;
            }
        }
    }
}

int w(int a, int b, int c){
    // cout<<a<<" "<<b<<" "<<c<<"\n";
    if (a<=0 || b<=0 || c<=0) return 1;
    else if (a>20 || b>20 || c>20) return w(20, 20, 20);
    
    if (!visited[a][b][c]) {
        visited[a][b][c] = true;
        if (a<b && b<c) dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        else dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}

int main(void){
    int a,b,c;
    dp_init();
    while (cin>>a>>b>>c){
        if (a==-1 && b==-1 && c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a, b, c)<<"\n";
    }
    return 0;
}