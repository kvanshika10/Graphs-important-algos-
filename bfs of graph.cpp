#include <bits/stdc++.h>

using namespace std;

void bfs(int s,vector<int> a[],bool visited[]){
    queue<int> q;
     q.push(s);
    visited[s]=true;

     while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout << curr << " ";
        for(int i=0;i<a[curr].size();i++){
            if(visited[a[curr][i]]==false){
                q.push(a[curr][i]);
                visited[a[curr][i]]=true;
            }
        }


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
    bfs(0,a,visited);

    return 0;
}

