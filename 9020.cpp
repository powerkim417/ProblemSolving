#include <iostream>

using namespace std;

bool isPrime[10001];

void init_prime(){
    for (int i=2 ; i<=10000 ; i++){
        isPrime[i] = true;
    }
    for (int p=2 ; p*p<=10000 ; p++){
        if (!isPrime[p]) continue;
        for (int i=p*p ; i<=10000 ; i+=p){
            isPrime[i] = false;
        }
    }
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    init_prime();
    int t;
    cin>>t;
    int n;
    while (t--){
        cin>>n;
        for (int b=n/2 ; b<=n ; b++){
            if (isPrime[b] && isPrime[n-b]){
                cout<<(n-b)<<" "<<b<<"\n";
                break;
            }
        }
    }
    return 0;
}