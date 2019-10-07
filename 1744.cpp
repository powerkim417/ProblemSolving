#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> pos, neg; // 2 이상 양수, 음수
    int one = 0;
    int zero = 0;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        if (temp == 1) one++;
        else if (temp == 0) zero++;
        else if (temp > 0) pos.push_back(temp);
        else if (temp < 0) neg.push_back(temp);
    }
    sort(pos.begin(), pos.end()); // 1 2 3
    reverse(pos.begin(), pos.end()); // 3 2 1
    sort(neg.begin(), neg.end()); // -3 -2 -1
    int answer = 0;
    /*  <양수 처리> 
    2 이상 양수는 a>b>c>d일 경우
    ab+cd > ac+bd? ab+cd > ad+bc?
    a(b-c)-d(b-c) = (a-d)(b-c) > 0,
    a(b-d)-c(b-d) = (a-c)(b-d) > 0 이므로
    ab+cd 가 가장 큰 경우임.
    
    1의 경우 + 1 + a 가 + (1*a) 보다 크므로
    묶지 않는다.
    */
    int pos_size = pos.size();
    // 7개면 01, 23, 45 곱하고 6번째 따로 더하기
    for (int i=0 ; i+1<pos_size ; i=i+2){
        answer += pos[i]*pos[i+1];
    }
    if (pos_size%2 == 1) answer += pos[pos_size-1];

    answer += one;

    /* 이제 0과 음수가 남았다
    -3 -2 -1 -1
    6 1
    음수는 -1 상관없이 그냥 다 짝지어서 곱해주고,
    음수 갯수가 홀수일 때
    0이 1개 이상 있으면 덮어서 없애버리고,
    0이 없으면 가장 절대값이 작은 음수를 어쩔 수 없이 빼는 식으로 한다.
    */

    int neg_size = neg.size();
    for (int i=0 ; i+1<neg_size ; i=i+2){
        answer += neg[i]*neg[i+1];
    }
    if (neg_size%2 == 1){
        if (zero > 0) {}
        else answer += neg[neg_size-1]; // 어쩔 수 없이 절대값이 가장 작은 음수를 뺌
    }
    cout<<answer;
}