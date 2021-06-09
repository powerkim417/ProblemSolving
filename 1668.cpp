#include <iostream>

using namespace std;

int arr[50];

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++) cin>>arr[i];

    // 왼쪽부터 봤을 때
    int h = 0, cnt = 0;
    for (int i=0 ; i<n ; i++) {
        if (arr[i] > h){
            cnt++;
            h = arr[i];
        }
    }
    cout<<cnt<<"\n";
    h = 0, cnt = 0;
    for (int i=n-1 ; i>=0 ; i--) {
        if (arr[i] > h){
            cnt++;
            h = arr[i];
        }
    }
    cout<<cnt;
    return 0;
}