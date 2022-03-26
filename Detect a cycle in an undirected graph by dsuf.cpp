#include <bits/stdc++.h>

using namespace std;

int find_op(int node ,int *parent,int *rankarr){

   if(parent[node]==-1)
     return node;
   return parent[node]=find_op(parent[node],parent,rankarr);


}
void unionfnctn (int n1,int n2,int *parent,int *rankarr){
   int x=find_op(n1,parent,rankarr);
   int y=find_op(n2,parent,rankarr);
   if(rankarr[x]>rankarr[y])
     parent[y]=x;
     else if (rankarr[y]>rankarr[x])
        parent[x]=y;
     else {parent[x]=y;rankarr[y]++;}

}

bool isCyclic(vector<pair<int,int>>a,int *parent,int *rankarr){

   for(auto k:a){
    int x=find_op(k.first,parent,rankarr);
   int y=find_op(k.second,parent,rankarr);
   if(x==y)
    return true;
    else unionfnctn(x,y,parent,rankarr);
   }
   return false;
}
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>>a;
    for(int i=0;i<e;i++){
            int u,v;
           cin >> u >> v;
        a.push_back({u,v});
    }
    int parent[n],rankarr[n];
    memset(parent,-1,n);
    memset(rankarr,0,n);
    cout << isCyclic(a,parent,rankarr);
    return 0;
}

