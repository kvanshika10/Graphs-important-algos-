#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,pair<int,int>>>adj;

    for(int i=0;i<e;i++){
             int u,v,w;
        cin >> u >> v >> w;
        adj.push_back({u,{v,w}});
    }
    int key[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;

    }
    key[0]=0;
        for(int i=0;i<n-1;i++){
         for(int j=0;j<e;j++){
                int u=adj[j].first;
                int v=adj[j].second.first;
                int w=adj[j].second.second;
            if(key[v]>key[u]+w){
                key[v]=key[u]+w;
                               }

                           }
                             }


            int j;
             for(j=0;j<e;j++){
                int u=adj[j].first;
                int v=adj[j].second.first;
                int w=adj[j].second.second;
               if(key[v]>key[u]+w){
                    break;
                  key[v]=w;}

                      }


    if(j!=e){
        cout << "Negative cycle";
    }else {
     for(int i=0;i<n;i++)
        cout << i << " " << key[i] << endl;
          }




}
