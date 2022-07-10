#include <iostream>

using namespace std;

int main(void){
    int n;
    while (cin>>n){
        if (n==0) break;
        int m=0, j=0, temp;
        while (n--){
            cin>>temp;
            if (temp==0) m++; else j++;
        }
        cout<<"Mary won "<<m<<" times and John won "<<j<<" times\n";
    }
    return 0;
}