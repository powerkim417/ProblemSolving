#include <iostream>

using namespace std;


int main(void){
    int n;
    cin>>n;
    int s, d, c;
    bool flag = false; // 0, 처음은 시계방향
    for (int i=0 ; i<n-1 ; i++){
        cin>>s>>d>>c;
        if (c) flag = !flag;
    }
    cout<<flag;
    return 0;
}