
#include <bits/stdc++.h>

using namespace std;

bool iscycle(int i,vector<int> a[],bool*visited,bool *dfsvisited){
      visited[i]=true;
      dfsvisited[i]=true;
   for(auto k:a[i]){
     if(!visited[k]){
        if(iscycle(k,a,visited,dfsvisited))return true;
        }else if(dfsvisited[k]==true)return true;

       }
       dfsvisited[i]=false;
  return false;


}

bool detectcycle(int n ,vector<int> a[]){
   bool visited[n];
  bool dfsvisited[n];int i;
 memset(visited,0,n);
    for(i=0;i<n;i++){
      if(!visited[i]){
    if(iscycle(i,a,visited,dfsvisited))
      return true;
    }
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
    }
     if(detectcycle(n,a))
  cout << "Cycle exists" << endl;
  else cout << "No cycle exist" << endl;

    return 0;
}

