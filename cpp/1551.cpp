#include <iostream>

using namespace std;

int arr[20];

int main(void){
    int n, k;
    cin>>n>>k;
    cin>>arr[0];
    char c; // 쉼표 처리
    for (int i=1 ; i<n ; i++){
        cin>>c>>arr[i];
    }
    for (int i=1 ; i<=k ; i++){
        for (int j=0 ; j<n-i ; j++){
            arr[j] = arr[j+1] - arr[j];
        }
    }
    cout<<arr[0];
    for (int i=1 ; i<n-k ; i++){
        cout<<","<<arr[i];
    }
    return 0;
}