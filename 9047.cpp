#include <iostream>

using namespace std;

int cnt[10];

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;
    while (t--){
        cin>>n;
        int answer = 0;
        while (n != 6174){
            for (int i=0 ; i<=9 ; i++) cnt[i]=0;
            int four=4;
            while (four--){ // n>0 으로 하면 n이 중간에 3자리 이하로 될 때 cnt가 총 4번 올라가지 않아서 문제가 됨
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
            n = big - small;
            answer++;
        }
        cout<<answer<<"\n";
    }
    return 0;
}