#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int operate(int a, int b, char op){
    switch (op){
        case '+':
        return a+b;
        case '-':
        return a-b;
        case '*':
        return a*b;
    }
}

int n;
vector<int> num;
vector<char> op; // 최대 9개
int ans = -2147483648;
int num_cnt, op_cnt;

// 두가지 선택지
// 1. 현재값 (연산자) 다음값
// 2. 현재값 (연산자) (다음값 연산자 다음다음값)
void dfs(int idx, int res){
    if (idx == op_cnt){
        if (ans < res) ans = res;
        return;
    }
    dfs(idx+1, operate(res, num[idx+1], op[idx]));

    if (idx+1 <= op_cnt-1){ // idx+1 번째 연산자까지 있음이 보장된 경우
        int temp = operate(num[idx+1], num[idx+2], op[idx+1]);
        dfs(idx+2, operate(res, temp, op[idx]));
    }
}

// DFS
// 중첩된 괄호 사용 불가
int main(void){
    cin>>n;
    num_cnt = (n+1)/2;
    op_cnt = n - num_cnt;
    char c;
    for (int i=0 ; i<n ; i++){
        cin>>c;
        if (i%2==0) num.push_back(c-'0');
        else op.push_back(c);
    }
    dfs(0, num[0]);
    cout<<ans;
    return 0;
}