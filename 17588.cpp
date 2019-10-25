#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    bool occur[201];
    int temp;
    int cnt = 0;
    for (int i=1 ; i<=200 ; i++) occur[i] = false;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        occur[temp] = true;
        cnt++;
    }
    // temp: 마지막 숫자
    if (cnt == temp) cout<<"good job";
    else {
        for (int i=1 ; i<=temp ; i++) {
            if (!occur[i]) cout<<i<<"\n";
        }
    }
}