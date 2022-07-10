#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// typedef pair<int, int> P; // <추천 수,

struct frame {
    int cnt; // 추천 수(높을 수록 우위)
    int time; // 게시된 타임스탬프(클 수록 우위, 같을 수는 없음)
    int num;
};

bool cmpByRec(frame a, frame b)
{
    // b가 크면 true
    if (a.cnt<b.cnt) return true;
    else if (a.cnt==b.cnt && a.time<b.time) return true;
    else return false;
}

bool cmpByNum(frame a, frame b)
{
    // b가 크면 true
    return (a.num<b.num);
}

bool exist[101] = {};
vector<frame> v;

// "2.어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다."
// 즉, 꽉 차있을 때 새 학생이 표를 받으면, 기존의 사진틀 중 꼴지가 몇 표를 받았든 지는 셈..
int main(void){
    int n, k;
    cin>>n>>k;
    int cur_size = 0;
    int rec;
    for (int i=0 ; i<k ; i++){
        cin>>rec;
        // cout<<"----INPUT: "<<rec<<"------\n";
        if (exist[rec]){ // 이미 걸려 있는 경우
            for (int j=0 ; j<v.size() ; j++){
                if (v[j].num == rec){
                    //cout<<"add "<<rec<<"'s point\n";
                    v[j].cnt++;
                    break;
                }
            }
        }
        else { // 새로 추천받은 경우
            if (v.size() < n){ // 칸 비어있는 경우
                v.push_back({1, i, rec});
                exist[rec] = true;
                // cout<<rec<<" inserted\n";
            }
            else { // 칸 꽉차서 교체해야 하는 경우
                exist[v[0].num] = false;
                exist[rec] = true;
                // cout<<rec<<" intercepted "<<v[0].num<<"\n";
                v[0] = {1, i, rec}; // 가장 낮은 후보를 밀어냄
            }
        }
        sort(v.begin(), v.end(), cmpByRec);
    }
    sort(v.begin(), v.end(), cmpByNum);
    for (int i=0 ; i<v.size() ; i++){
        cout<<v[i].num<<" ";
    }

}