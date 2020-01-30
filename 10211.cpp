#include <iostream>

using namespace std;

// 부분합

int main(void){
    int t;
    cin>>t;
    for (int tc=0 ; tc<t ; tc++){
        int n;
        cin>>n;
        int sum[n+1];
        sum[0] = 0;
        for (int i=1 ; i<=n ; i++){
            cin>>sum[i];
            sum[i] += sum[i-1];
        }
        int answer = -1000; // min: -999
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=i ; j++){
                if (sum[i]-sum[j-1] > answer){
                    answer = sum[i] - sum[j-1];
                }
            }
        }
        cout<<answer<<"\n";
    }
}