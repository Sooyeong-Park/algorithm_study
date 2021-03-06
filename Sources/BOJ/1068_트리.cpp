#include <iostream>
#include <vector>
using namespace std;
int del;
vector<int> adj[50];
bool visited[50];
int dfs(int here){ //깊이우선탐색
  visited[here] = true;
  int ret=0;
  for(auto there : adj[here])
    if(!visited[there])
      ret += dfs(there);
  if(ret==0) ret=1; //리프노드인 경우
  return ret;
}
int main()
{
  int n, root, leafs=0;
  cin >> n;
  for(int i=0; i<n; i++){
    int parent;
    cin >> parent;
    if(parent!=-1){
      adj[parent].push_back(i);
      adj[i].push_back(parent);
    }
    else root = i;
  }
  cin >> del;
  visited[del] = true; //지운 노드는 방문 안 해도 됨
  if(!visited[root]) leafs = dfs(root);
  cout << leafs << endl;
  return 0;
}
