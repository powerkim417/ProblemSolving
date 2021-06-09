#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int sa = 0, sb = 0;
    for (int i=0 ; i<n ; i++){
        int a, b;
        cin>>a>>b;
        if (a>b) sa += a+b;
        else if (a<b) sb += a+b;
        else {
            sa += a;
            sb += b;
        }
    }
    cout<<sa<<" "<<sb;
    return 0;
}