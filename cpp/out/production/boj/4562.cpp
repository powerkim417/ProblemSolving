#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int x,y;
    while (t--){
        cin>>x>>y;
        if (x<y) cout<<"NO BRAINS\n";
        else cout<<"MMM BRAINS\n";
    }
    return 0;
}