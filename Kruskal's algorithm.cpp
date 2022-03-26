#include <bits/stdc++.h>

using namespace std;

int find_op(int u,int *parent){
      if(u==parent[u])
        return u;
      return parent[u]=find_op(parent[u],parent);
}

void union_op(int n1,int n2,int *parent,int *rankarr){
   int x=find_op(n1,parent);
   int y=find_op(n2,parent);
   if(rankarr[x]>rankarr[y])
     parent[y]=x;
     else if (rankarr[y]>rankarr[x])
        parent[x]=y;
     else {parent[x]=y;rankarr[y]++;}

}

int main()
{
    int n,e,i;
    cin >> n >> e;
    vector<pair<int,pair<int,int>>>a,mst;
    for(i=0;i<e;i++){
            int u,v,w;
        cin >> u >> v >> w;
        a.push_back({w,{u,v}});
    }
      sort(a.begin(),a.end());
    int parent[n+1],rankarr[n+1];
    for(i=0;i<=n;i++){
        parent[i]=i;
        rankarr[i]=0;
    }
    int edges=0;
    for(auto k:a){
       int u=k.second.first;
        int v=k.second.second;
        if(find_op(u,parent)!=find_op(v,parent)){
        mst.push_back({k.first,{u,v}});
        union_op(u,v,parent,rankarr);
        edges++;
        }

        if(edges>=n-1)
            break;
    }
    for(auto k:mst){
        cout << k.second.first << " " << k.second.second << " " << k.first<< endl;
    }
    return 0;
}
// v-1 edges // connnected // undirected -kruskal and prims wont work
// tc-O(ELOGE+ELOGV)// ELOGE for sorting E LOGV every edge undergiung union find its complexity is logV after path copression
