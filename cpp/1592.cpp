#include <iostream>
using namespace std;
int main(void){
    int n,m,l;
    cin>>n>>m>>l;
    int cnt[n];
    for (int i=0 ; i<n ; i++){
        cnt[i] = 0;
    }
    int throwCount = 0;
    int curr = 0; //1이 가지고있음
    while (1) {
        cnt[curr]++;
        for (int i=0 ; i<n ; i++){
            if (cnt[i] >= m){
                cout<<throwCount;
                return 0;
            }
        }
        if (cnt[curr]%2 == 1){ //odd
            curr += (n-l);
            curr %= n;
        }
        else{ //even
            curr += l;
            curr %= n;
        }
        throwCount++;
    }
}