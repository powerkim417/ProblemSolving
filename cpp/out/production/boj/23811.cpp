#include <iostream>

using namespace std;

void oxxxx(int n, int line){
    for (int i=0 ; i<line*n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<"@";
        }
        cout<<"\n";
    }
}

void ooooo(int n, int line){
    for (int i=0 ; i<line*n ; i++){
        for (int j=0 ; j<5*n ; j++){
            cout<<"@";
        }
        cout<<"\n";
    }
}

// 골뱅이 찍기 모듈화
int main(void){
    int n; cin>>n;
    ooooo(n, 1);
    oxxxx(n, 1);
    ooooo(n, 1);
    oxxxx(n, 1);
    ooooo(n, 1);
    return 0;
}