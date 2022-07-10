#include <iostream>

using namespace std;

int dp[1000];

int main(void){
    int n;
    cin>>n;
    int a[1000];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    for (int i=0 ; i<n ; i++){
        int temp = 0;
        for (int j=0 ; j<i ; j++){
            if (a[j] >= a[i]) continue;
            if (dp[j] > temp) temp = dp[j];
        }
        dp[i] = temp + a[i];
    }
    int answer = -1;
    for (int i=0 ; i<n ; i++){
        if (answer < dp[i]) answer = dp[i];
    }
    cout<<answer;
    return 0;
}