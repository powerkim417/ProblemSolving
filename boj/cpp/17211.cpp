#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int n;
    cin>>n;
    double feel[n+1][2];
    bool now;
    cin>>now;
    feel[0][0] = ((now)?1:0); // 현재 싫은 날일 확률
    feel[0][1] = ((now)?0:1); // 현재 좋은 날일 확률
    double gg, gb, bg, bb;
    cin>>gg>>gb>>bg>>bb;
    for (int i=1 ; i<=n ; i++){
        feel[i][0] = feel[i-1][0]*bb + feel[i-1][1]*gb;
        feel[i][1] = feel[i-1][0]*bg + feel[i-1][1]*gg;
        // cout<<feel[i][1]<<" "<<feel[i][0]<<endl;
    }
    cout<<floor(feel[n][1]*1000+0.5)<<"\n"<<floor(feel[n][0]*1000+0.5);
}