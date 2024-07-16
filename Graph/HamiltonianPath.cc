/*
 * check if graph contains a Hamiltonian path, visit every vertex once
 * # of vertices must be less than 20 (N <= 20)
 */
int const N = 20;

bool dp[1 << N][N];
vector<int> g[N];

bool isHamiltonian(int n) {// number of nodes in the graph
    // 0-indexed
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = true;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask >> i & 1) == 0)
                continue;

            for (auto child: g[i]) {
                if (mask >> child & 1) {
                    //adjust your requirement
                    /*
                     * longest Hamiltonian path:
                     *      dp[mask][i] = max(dp[mask][i], dp[mask ^ (1 << i)][child] + 1 (can be some weight))
                     *
                     * number of hamiltonian paths:
                     *      dp[mask][i] = (dp[mask][i] + dp[mask ^ (1 << i)][child]) % MOD
                     *
                     * check whether graph contains Hamiltonian path
                     *      dp[mask][i] |= dp[mask ^ (1 << i)][child];
                     */

                }
            }
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j])
                //return true if there exist any hamiltonian path
                // maximize __builtin_popcount(i), if longest path required
                return true;
        }
    }
    /*
     * if number of paths required
     * return dp[(1 << n) - 1][n - 1];
     */
    return false;

}
