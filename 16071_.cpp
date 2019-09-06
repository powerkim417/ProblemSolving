#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct P {
    int u;
    int l;
    int d;
    int r;
};

P piece[300000];

void rotate(int idx){
    P& p = piece[idx];
    p = {p.l, p.d, p.r, p.u};
}

int main(void){
    int n;
    int h,w; // 일반성을 잃지 않고 h>=w 로 둔다. 가능한 방향 모두 정답으로 인정해주므로!
    cin>>n;
    int zero = 0;
    int p_zero;
    vector<int> three, two, one;
    vector<int> vertex, edge;
    // !!!!!!!!!!!!!!!!
    // n*1(0변 3개까지), 1*1(0변 4개)의 경우도 고려해야 함
    for (int t=1 ; t<=n ; t++){
        p_zero = 0;
        cin>>piece[t].u>>piece[t].l>>piece[t].d>>piece[t].r;
        if (piece[t].u==0) p_zero++;
        if (piece[t].l==0) p_zero++;
        if (piece[t].d==0) p_zero++;
        if (piece[t].r==0) p_zero++;
        if (p_zero == 2) {
            vertex.push_back(t);
        }
        else if (p_zero == 1) edge.push_back(t);
        zero += p_zero;
    }
    if (vertex.size() != 4){ // 꼭지점이 4개가 아닌 경우
        cout<<"impossible";
        return 0;
    }

    /* h*w = n, h+w = zero/2
    즉 x^2 - (zero/2)x + n = 0의 두 근이 h,w.
    근의 공식을 사용하면 x = (-b+-sqrt(b^2-4c))/2  */
    h = (zero + sqrt(zero*zero - 16*n)) / 4;
    w = (zero - sqrt(zero*zero - 16*n)) / 4;

    cout<<h<<" "<<w<<"\n";

    if (edge.size() != 2*(h+w-4)){ // 모서리 퍼즐 갯수가 안맞는 경우
        cout<<"impossible";
        return 0;
    }

    if (h+w != zero/2 || h*w != n) { // 직사각형 크기가 모서리로 견적이 안나오는 경우
        cout<<"impossible";
        return 0;
    }
    
    int puzzle[h][w];
    puzzle[0][0] = vertex[0];
    while ()
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<w ; j++){

        }
    }
}