#include <iostream>

using namespace std;

struct node {
    char left;
    char right;
};

node tree[26]; // 0:A, 1:B, ..

void preorder(char cur){
    if (cur != '.') cout<<cur;
    if (cur != '.') preorder(tree[cur-'A'].left);
    if (cur != '.') preorder(tree[cur-'A'].right);
}

void inorder(char cur){
    if (cur != '.') inorder(tree[cur-'A'].left);
    if (cur != '.') cout<<cur;
    if (cur != '.') inorder(tree[cur-'A'].right);
}

void postorder(char cur){
    if (cur != '.') postorder(tree[cur-'A'].left);
    if (cur != '.') postorder(tree[cur-'A'].right);
    if (cur != '.') cout<<cur;
}

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        char n,l,r;
        cin>>n>>l>>r;
        tree[n-'A'] = {l, r};
    }
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
}