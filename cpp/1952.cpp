#include <iostream>

using namespace std;

int n, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool visited[100][100] = {};

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}


int main(void){
    cin>>n>>m;
    int i=0, j=0, ni, nj;
    int cnt=1, ans=0;
    visited[0][0] = true;
    while (cnt<n*m){
        ni = i + dr[ans%4];
        nj = j + dc[ans%4];
        if (isRange(ni, nj) && !visited[ni][nj]){
            i = ni;
            j = nj;
        }
        else {
            ans++;
            // cout<<i<<" "<<j<<"\n";
            i += dr[ans%4];
            j += dc[ans%4];
        }
        visited[i][j] = true;
        cnt++;
    }
    cout<<ans;
}