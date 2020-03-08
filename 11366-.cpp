#include <iostream>

using namespace std;

// a나 b가 큰 수로 들어오면 초과가 난다고 함
// 이를 해결해야 함
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,n;
    while (1){
        cin>>a>>b>>n;
        if (a==0 && b==0 && n==0) break;
        for (int i=0 ; i<n ; i++){
            c = a+b;
            a = b;
            b = c;
        }
        cout<<c<<"\n";
    }
}