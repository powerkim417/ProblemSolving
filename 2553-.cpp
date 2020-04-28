#include <iostream>

using namespace std;

// 14! = .....1200
// 15! = ....6800
// 즉, 1의 자리만 가지고 하면 2*15=30 이라 3을 답으로 내놓지만 틀림!
// 이런 현상이 발생하는 이유는 2에서 8로 가는게 아니라 0으로 가고, 그 0들이 사라지면서 남는게 8이기 때문에
// 마지막 숫자끼리는 사실상 연관이 없다...

int main(void){
    int n;
    cin>>n;
    int answer = 1;
    for (int i=1 ; i<=n ; i++){
        answer *= i;
        while (answer%10 == 0) answer /= 10;
        answer %= 10;
    }
    cout<<answer;
    return 0;
}