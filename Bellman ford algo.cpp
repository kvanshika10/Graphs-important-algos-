#include <bits/stdc++.h>

using namespace std;

void print(vector<int>key,int V){

  for(int i=0;i<V;i++)
    cout <<i << " " << key[i] << endl;

}

void bellmanford(vector<pair<int,pair<int,int>>> mp,int V,int E){

    vector<int>key(V,INT_MAX);
    key[0]=0;int i;
  for(i=0;i<V-1;i++){

   for(auto k:mp){
    int w=k.first;
    int u=k.second.first;
    int v=k.second.second;
    if(key[u]!=INT_MAX&&key[u]+ w<key[v]){
        key[v]=key[u]+w;
    }
   }
  }

     for(auto k:mp){
    int w=k.first;
    int u=k.second.first;
    int v=k.second.second;
    if(key[u]!=INT_MAX&&key[u]+ w<key[v]){

                cout << "Negative weight cycle" << endl;
            return ;
    }

  }
   print(key,V);



}


int main()
{
    vector<pair<int,pair<int,int>>>mp;
    int V,E;
    cin >>V >> E;

        for(int j=0;j<E;j++){
                int a,b,c;
                cin >> a >> b >> c;
                mp.push_back({c,{a,b}});
    }

         bellmanford(mp,V, E);

    return 0;
}
