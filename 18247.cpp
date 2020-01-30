#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    for (int tc=0 ; tc<t ; tc++){
        int n,m;
        cin>>n>>m;
        if (n<12 || m<4) cout<<"-1\n";
        else cout<<(11*m + 4)<<"\n";
    }
}