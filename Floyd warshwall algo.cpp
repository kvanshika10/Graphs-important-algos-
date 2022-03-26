#include <iostream>

using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;
    int i,j;;
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)a[i][j]=0;
            else a[i][j]=INT_MAX;
        }

    }
    int u,v,w;
    for(i=0;i<e;i++){
        cin >> u >> v >> w;
        a[u][v]=w;

    }
    for(int k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][k]+a[k][j]<a[i][j]&&a[i][k]!=INT_MAX&&a[k][j]!=INT_MAX){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                if(a[i][j]==INT_MAX)
                cout << "infinity" << " ";
              else cout << a[i][j] << " ";

        }
        cout << endl;
    }
    return 0;
}
