#include <iostream>

using namespace std;

int main(void){
    int a, b, c;
    cin>>a>>b>>c;
    int sum = 9*1 + 7*3 + 8*1 + 0*3 + 9*1 + 2*3 + 1*1 + 4*3 + 1*1 + 8*3;
    sum += a+3*b+c;
    cout<<"The 1-3-sum is "<<sum;
    return 0;
}