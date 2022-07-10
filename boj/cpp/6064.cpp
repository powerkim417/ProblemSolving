#include <iostream>

using namespace std;

int gcd(int m, int n) {
    while (m != n) {
        if (m>n)
            m = m-n;
        else
            n = n-m;
    }
    return m;
}

int main(void){
    int t;
    cin>>t;
    for (int i=0 ; i<t ; i++){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        bool flag = false;
        // <3:1> = 13. 
        // 10a + 3 = 13
        // 12b + 1 = 13
        // 즉 x(mod m), y(mod n)을 만족하는 가장 작은 수를 찾아야 한다.
        int k = x;
        while (k <= m*n/gcd(m,n)){
            if (k%n == y%n){ // y=n이 되는 경우를 대비해 y%n으로
                flag = true;
                break;
            }
            else {
                k += m;
            }
        }
        if (flag) cout<<k<<endl;
        else cout<<"-1"<<endl;
    }
}