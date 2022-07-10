#include <iostream>

using namespace std;

int abs(int x){return (x>0)?x:-x;}

int main(void){
    int man[4];
    for (int i=1;  i<=3 ; i++){
        cin>>man[i];
    }
    int time = 1000*3;
    for (int i=1 ; i<=3 ; i++){
        int cur = 0;
        for (int j=1 ; j<=3 ; j++){
            cur += 2*abs(i-j)*man[j];
        }
        if (cur < time) time = cur;
    }
    cout<<time;
    return 0;
}