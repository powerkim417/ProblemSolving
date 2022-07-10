#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a=1, b=1;
    for (int i=2 ; i<=n ; i++){
        if (a==1){
            a = b+1;
            b = 1;
        }
        else {
            a--;
            b++;
        }
        // 이 작업이 끝나면 i번째 분수가 된다.
    }
    cout<<a<<" "<<b;
}