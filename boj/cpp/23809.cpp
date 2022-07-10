#include <iostream>

using namespace std;

int abs(int x){
    return (x>0)?x:-x;
}

void print(int n, int line){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<"@";
        }
        for (int j=0 ; j<n ; j++){
            if (line==2) cout<<"@";
            else cout<<" ";
        }
        for (int j=0 ; j<abs(2-line)*n ; j++){
            cout<<" ";
        }
        for (int j=0 ; j<n ; j++){
            cout<<"@";
        }
        cout<<"\n";
    }
}

// 골뱅이 찍기 모듈화
int main(void){
    int n; cin>>n;
    for (int i=0 ; i<5 ; i++){
        print(n, i);
    }
    return 0;
}