#include <iostream>

using namespace std;

int w,h,n;

int loc[101];

int min(int a, int b){
    return (a>b)?b:a;
}

int abs(int x){
    return (x>0)?x:-x;
}

// 블럭을 1차원으로 펴서 생각하는 풀이
// 북1-동4-남3-서2 로 펼쳤다고 가정
int main(void){
    cin>>w>>h>>n;
    int len = 2*(w+h);
    int dir, dist;
    for (int i=0 ; i<n+1 ; i++){
        cin>>dir>>dist;
        switch (dir){
            case 1:
            loc[i] = dist;
            break;
            case 2:
            loc[i] = w+h+(w-dist);
            break;
            case 3:
            loc[i] = w+h+w+(h-dist);
            break;
            case 4:
            loc[i] = w+dist;
            break;
        }
    }
    // loc[0~n-1]: 상점, loc[n]: 동근
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        int temp = abs(loc[n]-loc[i]);
        answer += min(temp, len-temp);
    }
    cout<<answer;
    return 0;
}