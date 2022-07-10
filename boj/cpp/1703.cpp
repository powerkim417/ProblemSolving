#include <iostream>

using namespace std;

int main(void){
    int a;
    int sf, cut;
    while (cin>>a){
        if (a==0) break;
        int ans = 1;
        for (int i=0 ; i<a ; i++){
            cin>>sf>>cut;
            ans *= sf;
            ans -= cut;
        }
        cout<<ans<<"\n";
    }
    return 0;
}