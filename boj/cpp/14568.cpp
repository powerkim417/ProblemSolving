#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    // 남규 >= 영훈+2
    // 영훈 = A
    // 택희 = 2B
    // N = 남+영+택 >= 2A + 2B + 2
    // A+B <= (N/2 - 1)
    // A, B는 자연수. 즉 N/2 - 1 >= 2. N>=6
    // 위 부정방정식의 해는 
    // A+B=2 ~ A+B=(N/2-1)의 모든 해.
    // 1 + 2 + .. + (N/2)-2
    // = ((N/2)-2)((N/2)-1) / 2
    if (n/2 - 1 >= 2) cout<<(((n/2)-2)*((n/2)-1) / 2);
    else cout<<"0";
}