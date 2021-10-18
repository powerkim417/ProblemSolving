#include <iostream>

using namespace std;

int cnt[10];

int main(void){
    int t;
    cin>>t;
    int n;
    while (t--){
        for (int i=0 ; i<=9 ; i++) cnt[i]=0;
        while (n>0){
            cnt[n%10]++;
            n /= 10;
        }
        int big = 0, small = 0;
        for (int i=9 ; i>=0 ; i--){
            for (int j=0 ; j<cnt[i] ; j++){
                big *= 10;
                big += i;
            }
        }
        for (int i=0 ; i<=9 ; i++){
            for (int j=0 ; j<cnt[i] ; j++){
                small *= 10;
                small += i;
            }
        }
        cout<<big<<" "<<small<<"\n";
    }
    return 0;
}