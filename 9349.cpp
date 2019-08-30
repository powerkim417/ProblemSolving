#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int n,k;
    for (int i=0 ; i<t ; i++){
        cin>>n>>k;
        int ans = (n-1)/(k-1) - 1;
        cout<<ans<<endl;
    }
}