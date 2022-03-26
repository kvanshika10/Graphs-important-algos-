#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,e;
    cin >> n>> e;
    vector<pair<int,int>> a[n];
    // step 1 adj list
    for(int i=0;i< e;i++){
            int u,v,w;
            cin >> u >>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
        }
        // three arrays or vectors
        int parent[n];// to store parent
        int key[n]; //to store weight
        bool mst[n]; // to store visited
    for(int i=0;i<n;i++){
        parent[i]=-1;key[i]=INT_MAX;mst[i]=0;
    }
    // now u have to include n-1 edges so you will do this process n-1 times
    key[0]=0;
    for(int count=0;count<n-1;count++){
        int u,mini=INT_MAX;
        for(int i=0;i<n;i++){

            if(mst[i]==false&&key[i]<mini){
                mini=key[i];u=i;

            }
        }

        mst[u]=true;
        for(auto k:a[u]){
            if(mst[k.first]==false&&key[k.first]>k.second){
                key[k.first]=k.second;parent[k.first]=u;}
        }

    }

    for(int i=1;i<n;i++){
        cout << i << " " << parent[i] << " " << key[i]<< endl;

    }
// tc -O(n^2)
//sc=0(3n)

    return 0;
}
