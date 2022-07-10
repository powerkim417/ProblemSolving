#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int temp;
    int cnt = 0;
    for (int i=0 ; i<5 ; i++){
        cin>>temp;
        if (temp == t) cnt++;
    }
    cout<<cnt;
}