#include <iostream>

using namespace std;

int main(void){
    int color[4] = {0, }; // R B Y G
    int num[10] = {0, }; // 0 안쓰고 1~9
    char c[5];
    int n[5];
    for (int i=0 ; i<5 ; i++){
        cin>>c[i]>>n[i];
        if (c[i]=='R') color[0]++;
        if (c[i]=='B') color[1]++;
        if (c[i]=='Y') color[2]++;
        if (c[i]=='G') color[3]++;
        num[n[i]]++;
    }

    // 귀찮..
}