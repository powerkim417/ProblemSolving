#include <iostream>

using namespace std;

int main(void){
    int T;
    cin>>T;
    for (int t=1 ; t<=T ; t++){
        int n;
        cin>>n;
        int front, back;
        // 0, 1, 2, .., n-1
        cin>>front;
        int cnt = 0;
        for (int j=1 ; j<=n-1 ; j++){
            cin>>back;
            if (front>=back) cnt++;
            front = back;
        }
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
}