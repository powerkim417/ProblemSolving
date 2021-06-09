#include <iostream>

using namespace std;

int main(void){
    int s, d, v;
    while (cin>>s>>d>>v){
        if (s==0 && d==0 && v==0) break;
        if ((v-s)%d==0) {
            if ((v-s)/d + 1 >= 1) cout<<((v-s)/d + 1)<<"\n";
            else cout<<"X\n"; // 수열상 뒤로 가는 경우도 나머지가 0이므로 제어해줘야 함
        }
        else cout<<"X\n";
    }
    return 0;
}