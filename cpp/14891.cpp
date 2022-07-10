#include <iostream>

using namespace std;

bool gear[5][8];
// 왼쪽 톱니의 2번 인덱스와 오른쪽 톱니의 6번 인덱스 비교

void rotate(int num, int dir){
    // 아래 긴 코드를 간소화시킨 버전!
    bool temp = gear[num][0];
    for (int i=0 ; i<=6 ; i++){
        gear[num][((-dir)*i+8)%8] = gear[num][((-dir)*i+8-dir)%8];
    }
    gear[num][(8+dir)%8] = temp;

    // if (dir==-1){
    //     bool temp = gear[num][0];
    //     gear[num][0] = gear[num][1];
    //     gear[num][1] = gear[num][2];
    //     gear[num][2] = gear[num][3];
    //     gear[num][3] = gear[num][4];
    //     gear[num][4] = gear[num][5];
    //     gear[num][5] = gear[num][6];
    //     gear[num][6] = gear[num][7];
    //     gear[num][7] = temp;
    // }
    // else {
    //     bool temp = gear[num][0];
    //     gear[num][0] = gear[num][7];
    //     gear[num][7] = gear[num][6];
    //     gear[num][6] = gear[num][5];
    //     gear[num][5] = gear[num][4];
    //     gear[num][4] = gear[num][3];
    //     gear[num][3] = gear[num][2];
    //     gear[num][2] = gear[num][1];
    //     gear[num][1] = temp;
    // }
}

void print(){
    for (int i=1 ; i<=4 ; i++){
        for (int j=0 ; j<8 ; j++){
            cout<<gear[i][j];
        }
        cout<<"\n";
    }
    cout<<"----------\n";
}

int main(void){
    char c;
    for (int i=1 ; i<=4 ; i++){
        for (int j=0 ; j<8 ; j++){
            cin>>c;
            (c == '1') ? gear[i][j] = true : gear[i][j] = false;
        }
    }
    int k;
    cin>>k;
    int num, dir;
    // cout<<"INITIAL STATE\n";
    // print();
    for (int t=0 ; t<k ; t++){
        cin>>num>>dir;
        // 1. 해당 톱니바퀴 먼저 회전
        rotate(num, dir);
        // cout<<num<<" rotated\n";
        // print();
        // 2. 양옆 톱니바퀴로 전파
        int left = num-1;
        int dir_temp = dir;
        // 왼쪽의 2번 인덱스와 기준의 6+dir번 인덱스(회전된 후이므로) 비교
        while (left>=1){
            if (gear[left][2] != gear[left+1][6+dir_temp]) {
                rotate(left, -dir_temp);
                left--;
                dir_temp *= -1;
                // cout<<(left+1)<<"'s left rotated\n";
                // print();
            }
            else break;
        }
        int right = num+1;
        dir_temp = dir;
        // 기준의 2+dir번 인덱스와 오른쪽의 6번 인덱스 비교
        while (right<=4){
            if (gear[right-1][2+dir_temp] != gear[right][6]) {
                rotate(right, -dir_temp);
                right++;
                dir_temp *= -1;
                // cout<<(right-1)<<"'s right rotated\n";
                // print();
            }
            else break;
        }
    }
    int score = 0;
    int temp = 1;
    for (int i=1 ; i<=4 ; i++){
        if (gear[i][0]) score += temp;
        temp *= 2;
    }
    cout<<score;
}