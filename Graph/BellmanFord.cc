#include <bits/stdc++.h>
using namespace std;

# define INF 10000000
int n, dist[200001];
vector<pair<int,int>, int> edges;

//shortest path from starting node to all nodes
//detects negative cycles
//recieves edge list, O(nm)
bool bellman_ford(int s) {
    // set distances to INF
    for (int i=1; i<=n; i++) dist[i]=INF;

    dist[s]=0;
    for (int i=1; i<=n-1; i++) {
        for (auto e:edges) {
            int a = e.first.first, b = e.first.second, w = e.second;
            dist[b] = min(dist[b], dist[a]+w);
        }
    }

    //last loop to check for negative cycles
    //true if there is a negative cycle
    for (auto e:edges) {
        int a = e.first.first, b = e.first.second, w = e.second;
        if (dist[a] + w < dist[b]) {
            return 1;
        }
    }
    return 0;
}
