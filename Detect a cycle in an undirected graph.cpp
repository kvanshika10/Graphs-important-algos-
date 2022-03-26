#include <bits/stdc++.h>

using namespace std;


bool iscycle(int i,int parent,vector<int> a[],bool*visited){
      visited[i]=true;
   for(auto k:a[i]){
     if(!visited[k]){
        if(iscycle(k,i,a,visited))return true;
        }else if(k!=parent)return true;
      
       }
  return false;
          

}

bool detectcycle(int n ,vector<int> a[]){ // simple dfs step
   bool visited[n];
  int parent[n],i;
  for(i=0;i<n;i++){
     parent[i]=-1;
 memset(visited,0,n);
    for(i=0;i<n;i++){
      if(!visited[i]){
    if(iscycle(i,-1,a,visited))
      return true;
    }
      return false;

    }
int main()
{
    int n,e;
    cout << "Enter the no of nodes and edges";
    cin >> n >> e;
    vector<int> a[n];

    int u,v;
    for(int i=0;i<e;i++){
        cin >> u>> v;
        a[u].push_back(v);
        a[v].push_back(u);

    }
     if(detectcycle(n,a))
  cout << "Cycle exists" << endl;
  else cout << "No cycle exist" << endl;
   
    return 0;
}

