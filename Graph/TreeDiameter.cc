int n, x, maxm;
vector<int> adj[200001];


void dfs(int s, int p, int depth) {
    for (int ne:adj[s]) {
        if (p==ne) continue;
        dfs(ne, s, depth+1);
    }
    if (depth > maxm) {
        maxm = depth;
        x = s;
    }
}

void diameter() {
    maxm=INT_MIN;

    //first dfs to find furthest node from 1
    dfs(1, 0, 0);
    
    //second dfs to find furthest node from x
    dfs(x, 0, 0);
}   


