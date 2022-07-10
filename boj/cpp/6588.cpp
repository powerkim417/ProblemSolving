#include <iostream>

using namespace std;

bool isPrime[1000001] = {};

void prime_init(){
    for (int i=0 ; i<=1000000 ; i++){
        isPrime[i] = true;
    }
    for (int i=2 ; i*i<=1000000 ; i++){
        if (!isPrime[i]) continue;
        for (int p=i*i ; p<=1000000 ; p+=i){
            isPrime[p] = false;
        }
    }
}

int main(void){
    prime_init();
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    bool found;
    while (cin>>n && n!=0){
        found = false;
        for (int a=3 ; a<=499999 ; a+=2){
            if (isPrime[a] && isPrime[n-a]){
                found = true;
                cout<<n<<" = "<<a<<" + "<<(n-a)<<"\n";
                break;
            }
        }
        if (!found) cout<<"Goldbach's conjecture is wrong.\n";
    }
    return 0;
}