#include <bits/stdc++.h>

using namespace std;


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
    int V=n,i;
     vector<int>in_degree(V,0);
     for(i=0;i<V;i++){
        for(auto k:a[i]){
            in_degree[k]++;
        }
     }
     queue<int>q;
     for(i=0;i<V;i++){
        if(in_degree[i]==0)
            q.push(i);
     }
     int cnt=0;
     vector<int>ans;
     while(!q.empty()){
           int curr=q.front();
           q.pop();
           ans.push_back(curr);
           for(i=0;i<a[curr].size();i++){
               in_degree[a[curr][i]]--;

               if(in_degree[a[curr][i]]==0)
                  q.push(a[curr][i]);

           }
        cnt++;
        }
     if(cnt!=V)
        cout <<"Cycle exist" << endl;
     else {
        for(auto k:ans)
            cout << k << " ";
     }
}

