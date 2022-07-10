#include <iostream>
using namespace std;

int f(int n, int b){
    int ret = 0;
    while (n>0){
        if (n%b!=0) break;
        ret++;
        n /= b; 
    }
    return ret;
}

int main(void){
    // 입력 최적화 필요
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t, n;
    cin>>t;
    for (int i=0 ; i<t ; i++){
        cin>>n;
        int answer = 0;
        for (int b=2 ; b<=n ; b++){
            answer += f(n, b);
        }
        cout<<answer<<"\n";
    }
    return 0;
}