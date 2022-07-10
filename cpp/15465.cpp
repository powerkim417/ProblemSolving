#include <iostream>
#include <vector>

using namespace std;

string names[3] = {"Bessie", "Elsie", "Mildred"};
int milk[3] = {7, 7, 7};

int nameToNum(string name){
    for (int i=0 ; i<3 ; i++){
        if (name.compare(names[i])==0) return i;
    }
}

// 값을 갱신할 때 중간에 있는 값을 수정해야 하므로 pq는 부적절.

// 요구사항: 생산량 1위 소 전광판을 변화시키는 날의 수를 구해야 한다.
/* 고려할 점
1. 동점이 되면 동점인 소를 모두 게시하게 되므로 이것도 변화
2. 하루에는 한 기록만 존재
3. 소의 수가 적어서 비트마스킹으로 접근함
*/

int main(void){
    int n;
    cin>>n;
    int day;
    string name;
    char sign;
    int delta;
    pair<int, int> measure[101] = {}; // <번호, 변화량>
    for (int i=0 ; i<n ; i++){
        cin>>day>>name>>sign>>delta;
        measure[day] = {nameToNum(name), (sign=='+')?delta:-delta};
    }
    int answer = 0;
    int max;
    int display = 0b111; // 3비트로 표시
    int temp;
    for (int i=1 ; i<=100 ; i++){
        if (measure[i] == make_pair(0, 0)) continue;
        milk[measure[i].first] += measure[i].second;
        max = milk[0];
        temp = 0b001; // 초기 상태: 0번이 최대값인 상태
        for (int j=1 ; j<3 ; j++){ //소가 m마리(<16)일 때에 대한 비트마스킹 풀이
            if (milk[j] > max){
                max = milk[j];
                temp = (1<<j);
            }
            else if (milk[j] == max){
                temp |= (1<<j);
            }
        }
        if (temp != display){
            answer++;
            display = temp;
        }
    }
    cout<<answer;
}