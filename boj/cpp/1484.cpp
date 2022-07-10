#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int g;
    cin>>g;
    // 몸무게: X(알던) -> Y(현재)
    // g = Y^2 - X^2 = (Y-X)*(Y+X)
    vector<int> Y;
    for (int i=1 ; i*i<=g ; i++){ // i <= i/g인 경우만
        if (g%i!=0) continue;
        // 이제 i와 g/i는 각각 Y-X, Y+X이다.
        if (i == g/i) continue; // 이 경우 X=0 이 되므로..
        if ((i+g/i)%2 == 1) continue; // 이 경우 Y가 홀수가 되므로..
        Y.push_back((i+g/i)/2);
    }
    int Y_size = Y.size();
    if (Y_size == 0){
        cout<<"-1";
        return 0;
    }
    for (int i=Y_size-1 ; i>=0 ; i--){
        cout<<Y[i]<<"\n";
    }
}