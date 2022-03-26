#include <bits/stdc++.h>

using namespace std;
#define V 5

int minimum (vector<int>key,vector<bool>mstset)
{
    int mini=INT_MAX;
    int minindex;
   for(int i=0;i<V;i++){
    if(mstset[i]==false&&key[i]<mini){
         mini=key[i];minindex=i;}
   }
   return minindex;
}

void print(int parent[],int graph[V][V]){
  for(int i=1;i<V;i++){
    cout << parent[i] << " " << i << " " << graph[i][parent[i]] << endl;
  }


}
void primsalgo(int graph[][V])
{

    int parent[V];
    vector<bool>mstset(V,false);
    vector<int>key(V,INT_MAX);

    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++){

        int u=minimum(key,mstset);
        mstset[u]=true;

        for(int v=0;v<V;v++){

            if(graph[u][v]!=0&&mstset[v]==false&&key[v]>graph[u][v]){
                key[v]=graph[u][v];parent[v]=u;}
        }
    }
            print(parent,graph);


}

int main()
{
    int graph[V][V]= { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

        primsalgo(graph);


    return 0;
}
