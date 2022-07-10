#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C,N;
    cin>>A>>B>>C>>N;
    int a, b, c;
    int answer = -1;
    for (int i=0 ; i<N ; i++){
        int cur = 0;
        for (int j=0 ; j<3 ; j++){
            cin>>a>>b>>c;
            cur += a*A + b*B + c*C;
        }
        if (cur > answer) answer = cur;
    }
    cout<<answer;
    return 0;
}