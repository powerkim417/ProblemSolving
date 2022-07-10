#include <iostream>

using namespace std;

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        int n,d;
        cin>>n>>d;
        int cnt = 0;
        for (int i=0 ; i<n ; i++){
            float v,f,c;
            cin>>v>>f>>c;
            // f/c = 연료 / 연료/시간 = 시간
            // v*(f/c) = 거리/시간 * 시간 = 거리
            if (v*f/c >= d) cnt++;
        }
        cout<<cnt<<"\n";
    }
}