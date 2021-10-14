#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        long long cur, sum=0;
        for (int i=0 ; i<n ; i++){
            cin>>cur;
            sum += cur;
            sum %= n;
        }
        if (sum%n == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}