#include <iostream>

using namespace std;

int main(void){
    int x1, y1, x2, y2; // 간판1
    int x3, y3, x4, y4; // 간판2
    int x5, y5, x6, y6; // 트럭
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;
    int answer = 0;
    for (int i=x1 ; i<x2 ; i++){
        for (int j=y1 ; j<y2 ; j++){
            if (i>=x5 && i<x6 && j>=y5 && j<y6) continue;
            // cout<<i<<" "<<j<<"\n";
            answer++;
        }
    }
    // cout<<"\n";
    for (int i=x3 ; i<x4 ; i++){
        for (int j=y3 ; j<y4 ; j++){
            if (i>=x5 && i<x6 && j>=y5 && j<y6) continue;
            // cout<<i<<" "<<j<<"\n";
            answer++;
        }
    }
    cout<<answer;
    return 0;
}