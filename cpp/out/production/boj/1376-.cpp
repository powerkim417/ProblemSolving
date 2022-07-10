#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<int> adj[100001];
void mfs(int x){
   visited[x] = true;
   cout<<x<<" ";
   int next;
   while (adj[x].size() > 0){
      if (adj[x].size()%2 == 0){
         next = adj[x].at(0);
      }
      else { // 홀수
         next = adj[x].at(adj[x].size()/2);
      }
      adj[x].erase(0);
      mfs(next);
   }
}

int main(void){
   int n,m;
   cin>>n>>m;
   int a, b;
   for (int i=1 ; i<=n ; i++){
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   for (int i=1 ; i<=n ; i++){
      sort(adj[i].begin(), adj[i].end());   
   }
   mfs(1);
}