#include <iostream>

using namespace std;

int main(void){
    int n,t,c,p;
    cin>>n>>t>>c>>p;
    int cnt = (n-1)/t;
    cout<<cnt*c*p;
}