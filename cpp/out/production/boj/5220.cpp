#include <iostream>

using namespace std;

int main(void){
    int t, n, c;
    cin>>t;
    for (int i=0 ; i<t ; i++){
        cin>>n>>c;
        int cnt = 0;
        while (n>0){
            if (n%2==1) cnt++;
            n /= 2;
        }
        if (cnt%2==c) cout<<"Valid\n";
        else cout<<"Corrupt\n";
    }
    return 0;
}