#include <iostream>

using namespace std;

int arr[50000][50000];

int calc(int n, int m){
    return calc()
}

int main(void){
    int T;
    cin>>T;
    int n, m;
    for (int i=0 ; i<50000 ; i++){
        arr[i][0] = 1;
        arr[0][i] = 1;
    }

    // R(n, m) = arr[n-m][m];
    // R(n+1,m+1) = (R(n,m) * R(n,m+1) + 1) / R(n-1,m)
    // R(n, m) = (R(n-1, m-1) * R(n-1, m) + 1) / R(n-2, m-1)
    // = (arr[n-m][m-1] * arr[n-m-1][m] + 1) / arr[n-m-1][m-1] 
    for (int t=0 ; t<T ; t++){
        cin>>n>>m;
    }
}