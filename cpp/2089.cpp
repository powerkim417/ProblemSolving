#include <iostream>
#include <vector>

using namespace std;

// -13 = 110111 (-32 + 16 + 0 + 4 + -2 + 1)
// 7 = 11011
// -3 = 1101
// 2 = 110
// -1 = 11
// 1 = 1


int main(void){
    int n;
    cin>>n;
    vector<int> answer;
    while (n!=1 && n!=0){
        answer.push_back(n%(-2) != 0); // -2로 안나눠 떨어지면 1 추가, 나눠 떨어지면 0 추가
        if (n<0) n = (n-1) / -2; // -13/-2 = -7이 나와야 하는데 -6이 나옴. 원하는 값을 갖기 위해 n이 음수일 때는 (n-1)/-2 를 해 나간다
        else n /= -2;
    }
    
    cout<<(bool)(n%(-2) != 0);
    for (int i=answer.size()-1 ; i>=0 ; i--){
        cout<<answer[i];
    }
    return 0;
}