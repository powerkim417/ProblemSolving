#include <iostream>

using namespace std;

void oxxxo(int n, int line){
    for (int i=0 ; i<line*n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<"@";
        }
        for (int j=0 ; j<3*n ; j++){
            cout<<" ";
        }
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
    oxxxo(n, 1);
    ooooo(n, 1);
    oxxxo(n, 1);
    ooooo(n, 1);
    oxxxo(n, 1);
    return 0;
}