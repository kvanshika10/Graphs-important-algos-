#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int>a[],bool *visited){
        visited[node]=true;
        for(auto k:a[node]){
            if(!visited[k])
                dfs(k,a,visited);
        }
    }

bool containsconnected(int n,vector<int>a[]){

 int i;
  for(i=0;i<n;i++){
    if(a[i].size()!=0)
    break;
  }
  if(i==n)
    return true;
  bool visited[n];
  memset(visited,0,n);
    dfs(i,a,visited);
    // check if there is any other component whose degree is not 0;
  for(i=0;i<n;i++){
    if(!visited[i]&&a[i].size()>0)
        return false;
  }
  return true;


}

int typeofgraph_degree(int n,vector<int>a[]){
     if(containsconnected(n,a)==false)
        return 0;
        int odd=0;
     for(int i=0;i<n;i++){
     if(a[i].size()%2!=0)
        odd++;
        if(odd>2)
            return 0;
     }
         if(odd==2)
         return 1;
       else return 2;

}
int main()
{
    // what is Euler path
    // the trail in which all edges are traversed once +start and end vertex may or may not be same
    // degree of all vertex are even except the start and end because start and end vertex are not same
    // what is Euler ckt
    // same as Euler path only difference is start and end vertex are same and degree of all vertex are even
    // must condition for Euler graph there must be only one connected component if there are more than one then their degree must be 0
  int t;
  cin >> t;
  while(t--){
    int n,e,i;
    cin >> n >> e;
    vector<int> a[n];
    int u,v;
    for(i=0;i<e;i++){
       cin >> u >>v;
       a[u].push_back(v);
       a[v].push_back(u);
    }
    if(typeofgraph_degree(n,a)==0)
    cout << "Not a Euler graph" << endl;
    else if(typeofgraph_degree(n,a)==1)
        cout << "Euler path or Semi Euler graph" << endl;
    else cout << "Euler Circuit or Euler graph" << endl;
  }

    return 0;
}
