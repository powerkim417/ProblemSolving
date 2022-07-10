#include <iostream>

using namespace std;

int dsum(int num, int base){
    int ret = 0;
    while (num > 0){
        ret += num%base;
        num /= base;
    }
    return ret;
}

int main(void){
    for (int i=1000 ; i<=9999 ; i++){
        if (dsum(i, 10) == dsum(i, 12) && dsum(i, 12) == dsum(i, 16)){
            cout<<i<<"\n";
        }
    }
}