#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<pair<int,int>,int>> edges, result; // (a, b, w)
    
int Kruskal_MST() {
    UnionFind uf(n+1);
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto p:edges) {
        int a = p.first.first, b = p.first.second, w = p.second;
        if (!uf.isSameSet(a, b)) {
            cost += w;
            result.push_back(p);
            uf.unionSet(a, b);
        }
    }
    return cost;
}