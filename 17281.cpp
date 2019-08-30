#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int hit[n][9];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<9 ; j++){
            scanf("%d", &hit[i][j]);
        }
    }
    vector<int> temp;
    for (int i=1 ; i<=8 ; i++) temp.push_back(i);
    
    int max = 0;
    do {
        vector<int> seq;
        for (int i=0 ; i<=2 ; i++) {
            seq.push_back(temp.at(i));
        }
        seq.push_back(0); // 4번타자: 1번 선수(0)
        for (int i=3 ; i<=7 ; i++) {
            seq.push_back(temp.at(i));
        }
        // for (int i=0 ; i<9 ; i++) {
        //     printf("%d", seq.at(i));
        // }
        // printf("\n");
        
        // 타순 선정 완료(1번 선수(0)가 4번째)
        int out = 0; // 아웃카운트
        int cur = 0; // 현 타순
        int inn = 0; // 현 이닝
        int score = 0;
        int player[9] = {0}; // 선수 번호 0~8 까지의 현 베이스 위치
        while (1){
            if (hit[inn][seq.at(cur)]!=0){ // 안타
                // printf("hit\n");
                for (int i=0 ; i<9 ; i++){
                    // 주자 또는 타자의 진루
                    if (player[i] != 0 || i==seq.at(cur)) {
                        player[i] += hit[inn][seq.at(cur)];
                    }
                }
                for (int i=0 ; i<9 ; i++){
                    // 홈을 통과한 주자가 있다면 점수를 추가하고, 베이스 초기화
                    if (player[i] >= 4) {
                        score++;
                        player[i] = 0;
                    }
                }
            }
            else { // 아웃
                // printf("out: %d\n", out);
                out++;
                if (out >= 3){ // 이닝 교체
                    // printf("inning %d finish\n", inn);
                    out = 0;
                    inn++;
                    if (inn >= n) {
                        break;
                    }
                    for (int i=0 ; i<9 ; i++) player[i] = 0;
                }
            }
            cur = (cur+1)%9;
        }
        if (max < score) max = score;
        // printf("%d\n", max);

    } while (next_permutation(temp.begin(), temp.end()));
    printf("%d", max);
}