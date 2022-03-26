#include<bits/stdc++.h>

using namespace std;

void dfs(int s,vector<int> a[],bool *visited,stack<int>&st){
       visited[s]=true;
       for(int i=0;i<a[s].size();i++){
          if(visited[a[s][i]]==false)
              dfs(a[s][i],a,visited,st);
       }
          st.push(s);
}

void reversedfs(int s,vector<int> a[],bool *vis){
    vis[s]=true;
    cout << s << " ";
       for(int i=0;i<a[s].size();i++){
          if(vis[a[s][i]]==false)
             reversedfs(a[s][i],a,vis);
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

    }
    stack<int>st;
    for(int i=0;i<n;i++){
        if(visited[i]==false)
        dfs(i,a,visited,st);
    }
      vector<int>b[n];
        for(int i=0;i<n;i++){
        for(auto k:a[i]){
            b[k].push_back(i);
        }

        }
        bool vis[n];
         memset(vis,0,n);
        while(!st.empty()){
          int x=st.top();
          st.pop();
          if(vis[x]==false){
               cout << "SCC" << " "; reversedfs(x,b,vis);
          cout <<  endl;
          }
        }

    return 0;
}
