#include <iostream>

using namespace std;

int main(void){
    // top-right에는 n^n 으로부터 (n-1)만큼 옆에 있는 값이 들어감
    int n;
    while (cin>>n){
        if (n==0) break;
        cout<<n<<" => "<<(n*n-n+1)<<"\n";
    }
    return 0;
}