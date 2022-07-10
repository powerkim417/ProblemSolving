#include <iostream>

using namespace std;

int calc(int base, int addtime, int cost){
    int ret = base;
    if (addtime < 0) return ret;
    else ret += addtime*cost*21;
    return ret;
}

int main(void){
    int a,x,b,y,t;
    cin>>a>>x>>b>>y>>t;
    cout<<calc(a, t-30, x)<<" "<<calc(b, t-45, y);
    return 0;
}