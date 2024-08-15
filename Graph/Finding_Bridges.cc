int n, m, u, v;
int timer = 1; // don't forget to initilize timer each iteration
int vis[N], tin[N], leastT[N];
vector<int> g[N];

void dfs_bridges(int node, int p){
    vis[node] = true;
    tin[node] = leastT[node] = timer++;
    for(auto nei : g[node]){
        if(nei == p)continue;
        if (!vis[nei]) {
            dfs_bridges(nei, node);
        }
        leastT[node] = min(leastT[node], leastT[nei]);
    }
    if(p != -1 && leastT[node] == tin[node]) {
        // edge (node, p) is bridge
        someFunctionWithBridge(node, p);
    }

}


void solve() {
    cin >> n >> m;
    timer = 1;
    for(int i = 1; i <= n; ++i)
        g[i].clear(), vis[i] = false;

    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs_bridges(i, -1);
        }
    
    }

}
