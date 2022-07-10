#include <iostream>

using namespace std;

int main(void){
    long long n;
    cin>>n;
    int ans = 1;
    for (int i=2 ; i<=n ; i++){
        ans *= i;
    }
    cout<<ans;
}