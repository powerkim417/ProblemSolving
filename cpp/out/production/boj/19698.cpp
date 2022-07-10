#include <iostream>

using namespace std;

int main(void){
    int n, w, h, l;
    cin>>n>>w>>h>>l;
    int ans = (w/l)*(h/l);
    if (ans > n) cout<<n;
    else cout<<ans;
    return 0;
}