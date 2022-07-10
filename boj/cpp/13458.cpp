#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[1000001], b, c;
    long cnt = 0;
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    cin>>b>>c;
    for (int i=0 ; i<n ; i++){
        int bu = ((a[i] >= b) ? ceil((a[i]*1.0-b)/c) : 0);
        cnt += bu + 1;
    }
    cout<<cnt;
}