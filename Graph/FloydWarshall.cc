#include <bits/stdc++.h>
using namespace std;

# define INF 10000000
int n, dist[105][105];
map<int,int> adj[105];


//shortest path for all pairs
//O(n^3)
void floyd_warshall() {
    for (int a=1; a<=n; a++) {
        for (int b=1; b<=n; b++) {
            if (a==b) dist[a][b]=0;
            else if (adj[a].count(b)) {
                dist[a][b]=adj[a][b];
            }
            else {
                dist[a][b] = INF;
            }
        }
    }

    for (int k = 1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

