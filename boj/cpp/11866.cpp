#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int n, k;
    cin>>n>>k;
    queue<int> q;
    for (int i=1 ; i<=n ; i++){
        q.push(i);
    }
    cout<<"<";
    while (!q.empty()){
        for (int i=0 ; i<k-1 ; i++){
            q.push(q.front());
            q.pop();
        }
        // k번째 차례
        cout<<q.front();
        q.pop();
        if (!q.empty()){
            cout<<", ";
        }
    }
    cout<<">";
}