#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[100];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    int x,y;
    cin>>x>>y;
    int cnt = 0;
    for (int i=0 ; i<n ; i++){
        if (a[i]>=y) cnt++;
    }
    cout<<n*x/100<<" "<<cnt;
    return 0;
}