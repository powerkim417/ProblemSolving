#include <iostream>

using namespace std;

bool isRange(char c){
    if (c>='0' && c<= '9') return true;
    else if (c>='a' && c<= 'z') return true;
    else if (c>='A' && c<= 'Z') return true;
    else return false;
}
int main(void){
    char map[5][16] = {};
    for (int i=0 ; i<5 ; i++){
        cin>>map[i];
    }
    for (int j=0 ; j<15 ; j++){
        for (int i=0 ; i<5 ; i++){
            if (!isRange(map[i][j])) continue;
            else cout<<map[i][j];
        }
    }
}