#include <iostream>

using namespace std;

int main(void){
    long long int r,c,n;
    cin>>r>>c>>n;
    // 각각 n으로 나눈 값을 올림한 값끼리의 곱이 답.
    cout<<((r-1)/n + 1)*((c-1)/n + 1);
}