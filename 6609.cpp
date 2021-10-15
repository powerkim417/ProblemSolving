#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int m,p,l,e,r,s,n;
    int newm, newp, newl;
    while (cin>>m>>p>>l>>e>>r>>s>>n){
        while (n--){
            newl = m*e;
            newp = l/r;
            newm = p/s;
            l = newl;
            p = newp;
            m = newm;
        }
        cout<<m<<"\n";
    }
    return 0;
}