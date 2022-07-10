#include <iostream>

using namespace std;

int main(void){
    char c;
    int cnt = 0;
    for (int i=0 ; i<6 ; i++){
        cin>>c;
        if (c=='W') cnt++;
    }
    if (cnt >= 5) cout<<"1";
    else if (cnt >= 3) cout<<"2";
    else if (cnt >= 1) cout<<"3";
    else cout<<"-1";
    return 0;
}