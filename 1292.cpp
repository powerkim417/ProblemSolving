#include <iostream>

using namespace std;

// 배열 저장 없이 풀어본 풀이
// #1, #2 모두 정답
int main(void){
    int a, b;
    cin>>a>>b;
    int sa = 0;
    int sb = 0;
    int num = 1;
    for (int i=1 ; i<=b ;){
        for (int j=0 ; j<num ; j++){
            // if (i==a) sa = sb; // S_{a-1}이 저장되어 있음 // #1
            sb += num;
            // cout<<"S["<<i<<"]="<<sb<<"\n";
            if (i==a-1) sa = sb; // #2
            if (i==b) {
                cout<<sb-sa; // S_{b} - S_{a-1}
                return 0;
            }
            i++;
        }
        num++;
    }
}