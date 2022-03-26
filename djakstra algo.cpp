#include <bits/stdc++.h>

using namespace std;
#define V 9

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

void print(vector<int> key){
  for(int i=0;i<V;i++){
    cout << i << " " << key[i] << endl;
  }


}
void djakstra(int graph[][V])
{

    vector<bool>mstset(V,false);
    vector<int>key(V,INT_MAX);

    key[0]=0;
    for(int count=0;count<V-1;count++){

        int u=minimum(key,mstset);
        mstset[u]=true;

        for(int v=0;v<V;v++){

            if(key[u]!=INT_MAX&&graph[u][v]!=0&&mstset[v]==false&&key[v]>key[u]+graph[u][v]){
                key[v]=key[u]+graph[u][v];}
        }
    }
            print(key);


}

int main()
{
        int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

       djakstra(graph);


    return 0;
}
