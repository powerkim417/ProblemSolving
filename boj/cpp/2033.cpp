#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=7 ; i++){
        double power = pow(10, i);
        if (n>power){
            n = round(n/power)*power;
        }
    }
    cout<<n;
}