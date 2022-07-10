#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

int main(void){
    int n;
    cin>>n;
    getchar();
    for (int t=0 ; t<n ; t++){
        int score[10][3];
        memset(score, 0, sizeof(score));
        string str, token;
        getline(cin, str);
        // stringstream을 이용하여 split
        istringstream iss(str);
        int frame = 0;
        int cnt = 1;
        while (getline(iss, token, ' ')){
            char c = token[0];
            if (cnt == 1){
                if (c >= '0' && c <= '9'){
                    score[frame] += c-'0';
                    cnt++;
                }
                else if(c == 'X'){
                    score[frame] += 10;
                    score[frame-1] += 10;
                    score[frame-2] += 10;
                    if (frame != 9) frame++;
                }
            }
            else if (cnt == 2){
                if (c >= '0' && c <= '9'){
                    score[frame] += c-'0';
                    cnt = 1;
                }
                else if(c == '/'){
                    score[frame] = 10;
                    score[frame-1] += 10;
                    frame++;
                }
                else if(c == 'X'){
                    score[frame] += 10;
                    score[frame-1] += 10;
                    score[frame-2] += 10;
                    if (frame != 9) frame++;
                }
            }
            else if (cnt == 3){
                if (c >= '0' && c <= '9'){
                    score[frame] += c-'0';
                }
                else if(c == '/'){
                    if (score[frame] >= 10) score[frame] = 20;
                    else score[frame] = 10;
                }
            }
        }
        int answer = 0;
        for (int i=0 ; i<10 ; i++){
            answer += score[i];
            cout<<score[i];
        }
        cout<<answer<<"\n";
    }
}