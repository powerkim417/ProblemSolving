#include <iostream>

using namespace std;

int cnt(int n, int x){
    int ret = n/x;
    if (n%x!=0) ret++;
    return ret;
}

int main(void){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int x = cnt(n, a)*b;
    int y = cnt(n, c)*d;
    cout<<(x>y ? y : x);
    return 0;
}