# define INF 10000000
int n, dist[200001];
bool vis[200001];
map<int,int> adj[200001];

//shortest path from starting node to all nodes
//doesn't work for graphs with -ve weighted edges
// Complexity: O(n + m log m)
void dijkstra(int s) {
    // set distances to INF
    for (int i=1; i<=n; i++) dist[i]=INF;

    dist[s]=0;

    //queue with lower weights first
    priority_queue<pair<int,int>> q;
    q.push({0, s});

    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if (vis[a]) 
            continue;
        
        vis[a] = 1;
        for (auto &[b, w]:adj[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}
