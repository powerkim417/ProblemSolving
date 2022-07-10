#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a = n/2;
    int b = n-a;
    // n=3일 때 a=1, b=2. -> 2*3 = 6
    // n=4일 때 a=2, b=2 -> 3*3 = 9
    cout<<(a+1)*(b+1);
}