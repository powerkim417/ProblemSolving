#include <iostream>

using namespace std;

string s, bomb;

/*
스택 문제라는데, 스택보단 그냥 스트링 활용 문제일듯
mirkovC4nizCC44 (폭탄 C4)의 경우
mirkovC4
mirkovC'4' 폭탄 문자열의 마지막 글자가 나오면
여기서 앞으로 깎아가면서 폭탄 문자열인지 확인
아니면 계속 쌓고, 맞는다면?
mirkov (폭탄 문자열에 해당하는 마지막 부분 문자열 삭제 후 마저 진행)
 */
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>s>>bomb;
    string answer = "";
    int bomb_size = bomb.size();
    for (int i=0 ; i<s.size() ; i++){
        answer += s[i];
        // if (answer.size() < bomb_size) continue; // 쌓인 글자의 수가 폭탄 길이보다 짧으면 검증할 필요 없음
        // 이 조건을 안넣어도 맞는 이유는.. 어차피 범위를 넘어간 *(answer.end()-1-j)가 *(bomb.end()-1-j)와 같을 리가 없기 때문!

        // 각 글자에 대해 폭탄의 마지막인지부터 시작해서 하나씩 앞을 살펴보는 단계
        // 중간에라도 폭탄이 아니라면 벗어남
        bool isBomb = true;
        for (int j=0 ; j<bomb_size ; j++){
            if (*(answer.end()-1-j) != *(bomb.end()-1-j)) { 
                isBomb = false;
                break;
            }
        }
        // cout<<i<<": "<<answer<<"\n";
        if (isBomb){
            // cout<<"bomb!\n";
            // answer = answer.substr(0, answer.size()-bomb_size); // O(N) 이므로 쓰면 안됨
            for (int j=0 ; j<bomb_size ; j++){
                answer.pop_back();
            }
        }
    }
    if (answer.size() == 0) cout<<"FRULA";
    else cout<<answer;
}