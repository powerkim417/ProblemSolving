#include <iostream>
#include <vector>
#include <bitset>
#include <cstdlib>
using namespace std;

// 스도쿠. 백트래킹 + 비트마스킹 사용

int map[9][9];

vector<pair<int, int>> hole;
int hbit[9] = {}; // i
int vbit[9] = {}; // j
int sbit[9] = {}; // 012 345 678 순서로 매길 때 -> (i/3)*3 + (j/3)
int hole_size;

void addBit(int &bit, int loc){ // loc+1: 해당 숫자
    bit |= (1<<loc);
}

void subBit(int &bit, int loc){ // loc+1: 해당 숫자
    bit &= ~(1<<loc);
}

bool checkBit(int &bit, int loc){
    return bit&(1<<loc);
}

int checkCommon(int &h, int &v, int &s){ // 셋의 공통 빈숫자가 1로 출력됨
    int temp = (~h)&(~v);
    return temp&(~s);
}

void dfs(int num, int cur_idx){
    // cur_idx번째 구멍에 num(0~8)을 넣으려 할 때(넣은 상태가 아님)
    pair<int, int> cur = hole[cur_idx];
    int candidates = checkCommon(hbit[cur.first], vbit[cur.second], sbit[(cur.first/3)*3+cur.second/3]);
    if (!checkBit(candidates, num)) return; // (가능한 숫자에 num이 없다)이미 차있으면 종료
    map[cur.first][cur.second] = num+1;
    // cout<<"map["<<cur.first<<"]["<<cur.second<<"] is "<<(num+1)<<"\n";
    addBit(hbit[cur.first], num);
    addBit(vbit[cur.second], num);
    addBit(sbit[(cur.first/3)*3+cur.second/3], num);
    if (cur_idx == hole_size-1){
        for (int i=0 ; i<9 ; i++){
            for (int j=0 ; j<9 ; j++){
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    for (int i=0 ; i<9 ; i++){ // temp의 0번 비트부터 8번 비트까지 확인
        dfs(i, cur_idx+1);
    }
    // cout<<"map["<<cur.first<<"]["<<cur.second<<"] return to hole\n";
    map[cur.first][cur.second] = 0;
    subBit(hbit[cur.first], num);
    subBit(vbit[cur.second], num);
    subBit(sbit[(cur.first/3)*3+cur.second/3], num);
}

int main(void){
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            cin>>map[i][j];
            if (map[i][j]==0) hole.push_back({i, j});
            else {
                addBit(hbit[i], map[i][j]-1);
                addBit(vbit[j], map[i][j]-1);
                addBit(sbit[(i/3)*3+j/3], map[i][j]-1);
            }
        }
    }
    // for (int i=0 ; i<9 ; i++){
    //     cout<<bitset<9>(hbit[i])<<"\n";
    // }
    // cout<<"---------\n";
    // for (int i=0 ; i<9 ; i++){
    //     cout<<bitset<9>(vbit[i])<<"\n";
    // }
    // cout<<"---------\n";
    // for (int i=0 ; i<9 ; i++){
    //     cout<<bitset<9>(sbit[i])<<"\n";
    // }
    hole_size = hole.size();
    if (hole_size==0){ // 구멍이 없는 경우는 dfs 함수 내에서 hole[0]을 접근하려는 곳에서 오류가 나므로 예외처리
        for (int i=0 ; i<9 ; i++){
            for (int j=0 ; j<9 ; j++){
                cout<<map[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    for (int i=0 ; i<9 ; i++) {
        dfs(i, 0); // 첫 칸에 i(0~8이 1~9를 의미)를 넣으며 시작 
    }
    return 0;
}