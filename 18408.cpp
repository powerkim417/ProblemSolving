#include <iostream>

using namespace std;

int main(void){
    int sum=0, temp;
    for (int i=0 ; i<3 ; i++){
        cin>>temp;
        sum += temp;
    }
    if (sum <= 4) cout<<"1"; // 111 112
    else cout<<"2"; // 122 222
    return 0;
}