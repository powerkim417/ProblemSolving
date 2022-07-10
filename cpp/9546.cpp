#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    for (int test_case=0 ; test_case<t ; test_case++){
        int k;
        cin>>k;
        // 정류장을 거칠 때마다 A -> A/2 - 1/2 가 된다
        // 반대로 역함수를 하면 2A+1 -> A 가 된다.
        // 즉, 2A+1를 k번 함수에 넣은 셈?
        // A -> 2A+1 -> 4A+3 -> 8A+7 -> ...
        // 그런데 A가 0이므로 index 0부터 각각 0, 1, 3, 7, 15, ...
        // 즉 답은 2^k - 1
        int answer = 1;
        for (int i=0 ; i<k ; i++){
            answer *= 2;
        }
        answer--;
        cout<<answer<<"\n";
    }
}