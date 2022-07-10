#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int next[100];
    for (int i=0 ; i<=99 ; i++){
        next[i] = (i%10)*10 + (i/10 + i%10)%10;
    }
    int cnt = 1;
    int temp = n;
    while (n != next[temp]){
        // cout<<temp<<"\n";
        temp = next[temp];
        cnt++;
    }
    cout<<cnt;
}