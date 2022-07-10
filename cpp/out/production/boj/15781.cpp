#include <iostream>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    int maxh = 0, maxa = 0, temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        if (temp>maxh) maxh = temp;
    }
    for (int i=0 ; i<m ; i++){
        cin>>temp;
        if (temp>maxa) maxa = temp;
    }
    cout<<(maxh+maxa);
}