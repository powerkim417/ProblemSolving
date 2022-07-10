#include <iostream>
#include <vector>

using namespace std;

int x[20], y[20]; // 최소, 최대

bool find(int bit, int k){
    return bit & (1<<k);
}

int cnt(int bit){
    int ret = 0;
    while (bit>0){
        if (bit%2==1) ret++;
        bit /= 2;
    }
    return ret;
}

// 비트마스킹(000111 조합으로 풀어도 되는데, 이러한 풀이를 비트마스킹으로 처음 해봄)
int main(void){
    int n, p, e;
    cin>>n>>p>>e;
    vector<int> answer;
    for (int i=0 ; i<n ; i++){
        cin>>x[i]>>y[i];
    }
    for (int bit=0 ; bit<(1<<n) ; bit++){
        // 비트 내 1의 갯수가 p개가 아니면 거름
        if (cnt(bit) != p) continue;

        int min = 0, max = 0;
        for (int i=0 ; i<n ; i++){
            if (find(bit, i)){
                min += x[i];
                max += y[i];
            }
        }
        if (min<=e && e<=max){
            // 우선 각 회원의 최소 요구량만큼 채워줌
            for (int i=0 ; i<n ; i++){
                if (find(bit, i)) {
                    answer.push_back(x[i]);
                    e -= x[i];
                }
                else answer.push_back(0);
            }
            // 남은 인형을 회원의 최대 요구량을 넘지 않는 선에서 채워줌
            for (int i=0 ; i<n ; i++){
                if (find(bit, i)) {
                    if (e>=(y[i]-x[i])){ // i번째 회원의 최대까지 지급
                        answer[i] += (y[i]-x[i]);
                        e -= (y[i]-x[i]);
                    }
                    else { // 최대값까지 다 못주고 여기서 끝나는 경우
                        answer[i] += e;
                        break;
                    }
                }
            }
            for (int i=0 ; i<n ; i++){
                cout<<answer[i]<<" ";
            }
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}