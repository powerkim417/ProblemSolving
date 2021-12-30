#include <iostream>

using namespace std;

int main(void){
    int n; cin>>n;
    int answer = 10+10+1;
    int row = -1;
    int col = -1;
    for (int r=1 ; r*r<=n ; r++){
        if (r + (n+r-1)/r < answer) {
            answer = r + (n+r-1)/r;
            row = r;
            col = (n+r-1)/r;
        }
    }
    cout<<row<<" "<<col;
    return 0;
}