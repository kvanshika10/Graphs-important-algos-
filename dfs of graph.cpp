#include <bits/stdc++.h>

using namespace std;
void dfs(int s,vector<int> a[],bool *visited){
       visited[s]=true;
       cout << s << " ";
       for(int i=0;i<a[s].size();i++){
          if(visited[a[s][i]]==false)
              dfs(a[s][i],a,visited);
       }


}

int main()
{
    int n,e;
    cout << "Enter the no of nodes and edges";
    cin >> n >> e;
    vector<int> a[n];
    bool visited[n];
    memset(visited,0,n);
    int u,v;
    for(int i=0;i<e;i++){
        cin >> u>> v;
        a[u].push_back(v);
        a[v].push_back(u); // for undirected graph
    }
    for(i=0;i<n;i++){
        if(!visited[i]){
           dfs(i,a,visited); 
        }
    }

    return 0;
}
