#include <bits/stdc++.h>

// N is array size, K >= ceil(log N)
const int K=25, N=200005;

int n, q, arr[N], table[K + 1][N], lg[N];

int fun(int a1, int a2) {
    return min(a1, a2);
}

int main() {
    compute_logs();
    
    cin >> n >> q;
    for (int i=0; i<n; i++) cin>>arr[i];
    
    for (int i=1; i<=K; i++) {
        for (int j=0; j + (1<<i) <= N; j++) {
            table[i][j] = fun(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }

    while(q--) {
        int l, r;
        cin>>l>>r; l--,r--;

        int i = lg[r - l + 1];
        cout << fun(table[i][l], table[i][r - (1<<i) + 1]) << "\n";
    }
}

void compute_logs() {
    lg[1] = 0;
    for (int i = 2; i <= N; i++) {
        lg[i] = lg[i/2] + 1;
    }
}