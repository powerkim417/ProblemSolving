#include <iostream>

using namespace std;

string code[8] = {"000000", "001111", "010011",
                "011100", "100110", "101001",
                "110101", "111010"};

int diff(string cur, int i){
    int ret = 0;
    for (int j=0 ; j<6 ; j++){
        if (cur[j] != code[i][j]) ret++;
    }
    return ret;
}

// 위에서 정해진 코드를 보면 한자만 다른 문자가 2개 이상일 수는 없음
// 즉, 차이가 1개면 그게 답
// 매치 안되면 -1 반환
int match(string cur){
    int d = 7;
    int ret = -1;
    for (int i=0 ; i<8 ; i++){
        if (d > diff(cur, i)){
            d = diff(cur, i);
            if (d<2) ret = i;
        }
    }
    return ret;
}

int main(void){
    int n;
    string s, cur;
    cin>>n>>s;
    string answer = "";
    for (int i=0 ; i<n ; i++){
        cur = s.substr(6*i, 6);
        if (match(cur) != -1) answer += (char)(match(cur)+'A');
        else {
            cout<<(i+1);
            return 0;
        }
    }
    cout<<answer;
    return 0;
}