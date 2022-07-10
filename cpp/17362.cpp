#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    // 1 2 3 4 5
    //   8 7 6
    // 위의 모든 숫자에 8씩을 더함.
    // 9 10 11 12 13
    //   16 15 14 ...
    switch (n%8){
        case 1:
            cout<<"1";
            break;
        case 0:
        case 2:
            cout<<"2";
            break;
        case 3:
        case 7:
            cout<<"3";
            break;
        case 4:
        case 6:
            cout<<"4";
            break;
        case 5:
            cout<<"5";
            break;
    } 
}