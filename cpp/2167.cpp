#include <iostream>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    int a[n][m], sum[n][m];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>a[i][j];
            sum[i][j] = a[i][j];
            if (i==0 && j!=0) sum[i][j] += sum[i][j-1];
            else if (j==0 && i!=0) sum[i][j] += sum[i-1][j];
            else if (i!=0 && j!=0){
                sum[i][j] = a[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
    }
    /* sum[n][m] 값 채우는 방법
    모서리의 경우는 그때그때 채우고
    안쪽의 경우는 sum[n][m] = a[n][m] + sum[n][m-1] + sum[n-1][m] - sum[n-1][m-1]
    */
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int k, i, j, x, y;
    cin>>k;
    for (int t=0 ; t<k ; t++){
        cin>>i>>j>>x>>y;
        i--;
        j--;
        x--;
        y--;
        int answer = sum[x][y];
        if (i>0) answer -= sum[i-1][y];
        if (j>0) answer -= sum[x][j-1];
        if (i>0 && j>0) answer += sum[i-1][j-1];
        cout<<answer<<"\n";
    }
}