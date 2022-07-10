#include <iostream>

using namespace std;

int main(void){
    double t,p;
    cin>>t>>p;
    // t분동안 100에서 p가 됨
    double answer;
    if (p>=20){
        // p~20 + 20~0
        answer = (p-20)/((100-p)/t) + 20/(((100-p)/t)/2);
    }
    else {
        // p~0
        // 처음 속도를 v라고 하면 간 거리는 100~20 + 20~p
        // 80/v + (20-p)/(v/2) = t
        // (120-2p)/v = t
        // v = (120-2p)/t
        answer = p/(((120-2*p)/t)/2);
    }
    cout<<answer;
    return 0;
}