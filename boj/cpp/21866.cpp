#include <iostream>

using namespace std;

int main(void){
    int score;
    int max;
    int sum = 0;
    for (int i=0 ; i<9 ; i++) {
        cin>>score;
        sum += score;
        max = 100*(i/2 + 1);
        if (score > max) {
            cout<<"hacker";
            return 0;
        }
    }
    if (sum >= 100) cout<<"draw";
    else cout<<"none";
    return 0;
}