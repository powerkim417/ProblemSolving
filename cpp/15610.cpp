#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long long a;
    double ans;
    cin>>a;
    ans = sqrt(a);
    cout<<fixed;
    cout.precision(6);
    cout<<4*ans;
    return 0;
}