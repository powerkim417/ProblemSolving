#include <iostream>

using namespace std;

int main(void){
    int arr[6];
    for (int i=0 ; i<6 ; i++){
        cin>>arr[i];
    }
    int ans = 0;
    for (int i=0 ; i<3 ; i++){
        if (arr[i]<arr[i+3]) ans += arr[i+3]-arr[i];
    }
    cout<<ans;
    return 0;
}