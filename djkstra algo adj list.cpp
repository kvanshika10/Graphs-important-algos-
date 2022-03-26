#include <bits/stdc++.h>

using namespace std;
// TIME COMPLEXITY -O((V+E)LOGV)
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>>adj[n];
    int u,v,w;
    for(int i=0;i<e;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bool mstset[n];
    int key[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstset[i]=0;
    }
    key[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});// vertices ,weight// reverse
    for(int i=0;i<n;i++){
        int u=pq.top().second;
        pq.pop();
        mstset[u]=true;
        for(auto k:adj[u]){
                int v=k.first;
            if(mstset[v]==false&&key[v]>key[u]+k.second){
                key[v]=key[u]+k.second;
                pq.push({key[v],v});

                }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " " << key[i] << endl;
    }
    // TC -O(V+E);
    return 0;
}
