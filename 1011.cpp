#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    int x, y;
    /*
    거리 - 최소횟수
    1 - 1(1)
    
    2 - 2(1 1)
    
    3 - 3(1 1 1)
    4 - 3(1 2 1)
    
    5 - 4(1 2 1 1)
    6 - 4(1 2 2 1)

    7 - 5(1 2 2 1 1)
    9 - 5(1 2 3 2 1)

    10 - 6(1 2 2 2 2 1)
    12 - 6(1 2 3 3 2 1)

    y-x - 
    */
    for (int test=0 ; test<t ; test++){
        cin>>x>>y;
    }
    return 0;
}