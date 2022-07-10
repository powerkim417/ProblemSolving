#include <iostream>

using namespace std;

int main(void){
    int n;
    string s;
    cin>>n>>s;
    char answer = s[n-1];
    for (int i=n-2 ; i>=0 ; i--){
        // an = answer, an-1 = s[i]
        if (answer != s[i]) { // 두개가 다른 경우
            if (answer == 'A'){
                if (s[i] == 'G') answer = 'C';
                if (s[i] == 'C') answer = 'A';
                if (s[i] == 'T') answer = 'G';
            }
            else if (answer == 'G'){
                if (s[i] == 'A') answer = 'C';
                if (s[i] == 'C') answer = 'T';
                if (s[i] == 'T') answer = 'A';
            }
            else if (answer == 'C'){
                if (s[i] == 'A') answer = 'A';
                if (s[i] == 'G') answer = 'T';
                if (s[i] == 'T') answer = 'G';
            }
            else { // answer == 'T'
                if (s[i] == 'A') answer = 'G';
                if (s[i] == 'G') answer = 'A';
                if (s[i] == 'C') answer = 'G';
            }
        }
        // 같은 경우는 answer가 바뀌지 않으므로 처리할게 없음
    }
    cout<<answer;
    return 0;
}