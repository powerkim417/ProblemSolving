#include <iostream>

using namespace std;

int min(int a, int b){
    return (a>b)?b:a;
}

// x + y + z = a[i]
// x + y = a[i] - z 
int main(void){
    int n;
    cin>>n;
    int arr[5000];
    int good[400001] = {}; // 2개의 수로 i-200000을 표현할 수 있게 되는 배열의 인덱스 숫자.
    // -200,000<=(2개의 수의 합)<=200,000
    for (int i=0 ; i<=400000 ; i++) good[i] = 5000; // 되지 않을 인덱스로 초기화
    for (int i=0 ; i<n ; i++){ // x
        cin>>arr[i];
        for (int j=0 ; j<=i ; j++){ // y
            if (good[arr[i]+arr[j]+200000]==5000) good[arr[i]+arr[j]+200000] = i;
        }
    }
    // for (int i=0 ; i<=22 ; i++){
    //     cout<<"good["<<i<<"] = "<<good[i+200000]<<"\n";
    // }
    int cnt = 0;
    for (int i=1 ; i<n ; i++){ // a[i]
        for (int j=0 ; j<i ; j++){ // z
            if (good[arr[i]-arr[j]+200000] < i){
                // cout<<arr[i]<<" is able\n";
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}