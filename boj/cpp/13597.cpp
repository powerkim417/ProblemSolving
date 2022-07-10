#include <iostream>

using namespace std;

int main(void){
    int a,b;
    cin>>a>>b;
    if (b>a) {
        int temp = b;
        b = a;
        a = temp;
    }
    // Now, a>=b

    if (a==b){
        cout<<a;
    }
    else {
        cout<<a;
    }
}