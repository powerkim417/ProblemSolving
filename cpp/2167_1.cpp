#include <iostream>

using namespace std;

int n, m;
int arr[301][301]; // 1~300
int sum[301][301] = {}; // 0이 들어가는 칸은 0으로 채운다.
// 

// i j x y 일 때
// Sxy - S(i-1)y - Sx(j-1) + S(i-1)(j-1) 가 답이 된다.

/*
sum[n][m] 값 채우는 방법
모서리의 경우는 그때그때 채우고
안쪽의 경우는 sum[n][m] = a[n][m] + sum[n][m-1] + sum[n-1][m] - sum[n-1][m-1]
이렇게 푸는 것이 시간이 더 적게 걸린다...
(이 코드에서는 4중포문으로 풀음)
*/

int main(void){
    cin>>n>>m;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            cin>>arr[i][j];
            for (int ii=1 ; ii<=i ; ii++){
                for (int jj=1 ; jj<=j ; jj++){
                    sum[i][j] += arr[ii][jj];
                }
            }
        }
    }
    int k;
    cin>>k;
    int i,j,x,y;
    for (int t=0 ; t<k ; t++){
        cin>>i>>j>>x>>y;
        cout<<(sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1])<<"\n";
    }
}