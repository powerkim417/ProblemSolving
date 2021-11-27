#include <iostream>

using namespace std;

int n, m;
int cnt[50][4] = {};
char dna[1000][50];
string seq = "ACGT";

int dist(int a, int b){
    int ret = 0;
    for (int j=0 ; j<m ; j++){
        if (dna[a][j]!=dna[b][j]) ret++;
    }
    return ret;
}

void add_cnt(char c, int j){
    for (int k=0 ; k<4 ; k++){
        if (c==seq[k]) cnt[j][k]++;
    }
}

pair<char, int> get_letter(int j){
    char retc;
    int reti = -1;
    for (int k=0 ; k<4 ; k++)
    if (cnt[j][k] > reti){
        retc = seq[k];
        reti = cnt[j][k];
    }
    reti = n-reti; // 주류의 갯수가 아니라, 전체에서 이를 제외한 갯수가 되어야 함
    return {retc, reti};   
}

// n개중 하나를 고르는게 아니고, 가능한 dna중 HD가 가장 작은 애를 새로 구하는 것
// 각 자리에서 봤을 때, 가장 많이 등장한 알파벳을 채택하면 됨
// 왜냐하면, 특정 dna가 n개의 dna와 가지는 HD의 합은
// 결국 n*m 크기의 보드 기준으로 봤을 때 해당 위치와 다른 알파벳의 갯수를 세는 것이므로
// 다른 경우가 제일 조금 나오려면 가장 많이 등장하는 알파벳으로 넣어줘야 함
int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>dna[i][j];
            add_cnt(dna[i][j], j);
        }
    }
    int answer = 0;
    for (int j=0 ; j<m ; j++){
        pair<char, int> cur = get_letter(j);
        cout<<cur.first;
        answer += cur.second;
    }
    cout<<"\n"<<answer;
    return 0;
}