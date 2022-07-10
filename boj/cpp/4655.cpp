#include <iostream>

using namespace std;

int main(void){
    double c;
    double len = 0;
    int n = 1;
    while (cin>>c){
        if (c==0) break;
        len = 0;
        n = 0;
        while (len < c){
            n++;
            len += 1.0/(n+1);
        }
        cout<<n<<" card(s)\n";
    }
    return 0;
}