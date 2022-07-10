#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[26]; // 0:A 1:B 등등.. 첫번째 원소는 왼쪽 자식이고 두번째 원소는 오른쪽 자식. 원소가 '.'인 경우 자식이 없는 것

void preorder(int cur){
    cout<<(char)(cur+'A');
    if (nodes[cur][0]+'A' != '.') preorder(nodes[cur][0]);
    if (nodes[cur][1]+'A' != '.') preorder(nodes[cur][1]);
}

void inorder(int cur){
    if (nodes[cur][0]+'A' != '.') inorder(nodes[cur][0]);
    cout<<(char)(cur+'A');
    if (nodes[cur][1]+'A' != '.') inorder(nodes[cur][1]);
}

void postorder(int cur){
    if (nodes[cur][0]+'A' != '.') postorder(nodes[cur][0]);
    if (nodes[cur][1]+'A' != '.') postorder(nodes[cur][1]);
    cout<<(char)(cur+'A');
}

int main(void){
    int n;
    cin>>n;
    char c,l,r;
    for (int i=0 ; i<n ; i++){
        cin>>c>>l>>r;
        nodes[c-'A'].push_back(l-'A');
        nodes[c-'A'].push_back(r-'A');
    }
    preorder(0);
    cout<<"\n";
    inorder(0);
    cout<<"\n";
    postorder(0);
}