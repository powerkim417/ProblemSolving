#include <iostream>

using namespace std;

typedef unsigned long long ull;
int n, q;
ull p, k, c;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int num = 0;
    ull cost = (1ULL<<63)-1;
    for (int i=1 ; i<=n ; i++){
        cin>>p>>k>>c;
        ull cnt = (q-1)/k;
        ull temp = p + c*cnt*(cnt+1)/2;
        if (temp < cost){
            cost = temp;
            num = i;
        }
    }
    cout<<num<<" "<<cost;
    return 0;
}