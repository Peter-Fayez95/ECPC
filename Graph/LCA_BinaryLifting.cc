vector<vector<int>> g;//tree representation
int depth[N], up[N][20];
/*
 definition for the binary lifting array

    [i][j] ==> for the node i the 2^j-th ancestor is up[i][j]
 */

void init() {
    depth[1] = 0;
    for (int i = 0; i < 20; ++i)
        up[1][i] = 1;
}

void dfs(int node,int parent) {
    for (auto child: g[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            for (int j = 1; j < 20; ++j)
                up[child][j] = up[up[child][j - 1]][j - 1];
            dfs(child,node);
        }
    }
}

int getLca(int a, int b) {
    if (depth[a] < depth[b])// make (a) the farthest from 1
        swap(a, b);
    int k = depth[a] - depth[b];// get the diff
    for (int i = 0; i < 20; ++i)
        if (k >> i & 1)
            a = up[a][i];

    if (a == b)
        return a;
    for (int i = 19; i >= 0; --i)
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    return up[a][0];
}
/*
 for dist between u,v
 dist = depth[u] + depth[v] - 2 * depth[lca(u,v)]
 */
