#include <iostream>

using namespace std;

int leftChild[26];
int rightChild[26];

// 노드를 설계하지 않고 해결한 풀이

void pre(int cur){
    if (cur == '.'-'A') return;
    cout<<(char)(cur+'A');
    pre(leftChild[cur]);
    pre(rightChild[cur]);
}

void in(int cur){
    if (cur == '.'-'A') return;
    in(leftChild[cur]);
    cout<<(char)(cur+'A');
    in(rightChild[cur]);
}

void post(int cur){
    if (cur == '.'-'A') return;
    post(leftChild[cur]);
    post(rightChild[cur]);
    cout<<(char)(cur+'A');
}

int main(void){
    int n;
    cin>>n;
    char c, l, r;
    for (int i=0 ; i<n ; i++){
        cin>>c>>l>>r;
        leftChild[c-'A'] = l-'A';
        rightChild[c-'A'] = r-'A';
    }
    pre(0);
    cout<<"\n";
    in(0);
    cout<<"\n";
    post(0);
    return 0;
}