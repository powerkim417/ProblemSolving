#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 개미가 충돌하는 경우는
개미끼리 통과하는 경우와 개미의 종류만 바뀌었을 뿐,
위치 변화는 같다!
그러므로 가장 마지막에 떨어지는 시간은 그냥 각 개미가 끝에 도달하는 최종 시간이고,
마지막 개미는 ..
*/

struct ant_struct {
    int loc;
    int dir; // 1, -1
    int num;
};

vector<ant_struct> ant; // 위치, 번호

int abs(int x){
    if (x<0) return -x;
    else return x;
}

bool cmpByLoc(const ant_struct &a, const ant_struct &b)
{
    return (a.loc < b.loc);
}

int main(void){
    int l, n;
    // 0 < 좌표 < l
    cin>>n>>l;
    int time = -1;
    int fake_num = -1;
    // 개미가 통과한다고 가정할 때의 가짜 번호를 저장.
    // 충돌마다 번호가 전달된다고 치면,
    // 해당 가짜 번호에서 충돌 수만큼
    // 해당 방향으로 이동한 개미가 진짜 번호!

    // 충돌 수는 통과 기준 가장 오래 걸리는 개미와 반대 방향인 개미의 수.
    int temp;
    ant.push_back({0, 0, 0});
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        if (temp>0) ant.push_back({temp, 1, i});
        else ant.push_back({-temp, -1, i});
        if (ant[i].dir>0){ // 우향
            if (time < l-ant[i].loc) {
                fake_num = i;
                time = l-ant[i].loc;
            }
        }
        else { // 좌향
            if (time < ant[i].loc-0) {
                fake_num = i;
                time = ant[i].loc;
            }
        }
    }

    sort(ant.begin()+1, ant.end(), cmpByLoc); // 별 처리 없을 경우 first, 즉 위치에 의해 sort됨
    
    int coll = 0;
    int fake_idx;
    for (int i=1 ; i<=n ; i++){ // 정렬된 fake_num ant의 위치 찾기
        if (ant[i].num == fake_num){
            fake_idx = i;
        }
    }

    if (ant[fake_idx].dir<0){ // 좌향인 경우
        for (int i=1 ; i<=n ; i++){ // 부호 다르고(양수), 절대값은 더 작은 애들 카운트
            if (ant[i].dir > 0 && ant[i].loc < ant[fake_idx].loc) coll--; // 어차피 횟수 더한 뒤 음수로 더할 것이므로 빼준다.
        }
    }
    else { // 우향인 경우
        for (int i=1 ; i<=n ; i++){ // 부호 다르고(음수), 절대값은 더 큰 애들 카운트
            if (ant[i].dir < 0 && ant[i].loc > ant[fake_idx].loc) coll++;
        }
    }

    // cout<<fake_num<<" "<<fake_idx<<" "<<coll<<endl;

    int real_num = ant[fake_idx + coll].num;
    cout<<real_num<<" "<<time;
}