#include <bits/stdc++.h>

using namespace std;
stack<int> s;

void topologicalsort(int node,vector<int> a[],bool *visited)
{
    visited[node]=true;
    for(int i=0;i<a[node].size();i++){
            if(visited[a[node][i]]==false)
            topologicalsort(a[node][i],a,visited);

    }
    s.push(node);

}

int main()
{

int n,e;\

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
     for(int i=0;i<n;i++){
            if(visited[i]==false)
    topologicalsort(i,a,visited);
     }
    //cout << s.size() << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
// time c-O(V+E)// same as DFS
// space complexity-O(V)// stack memory
// used in file dependencies 