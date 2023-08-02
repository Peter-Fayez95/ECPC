#include <bits/stdc++.h>

using namespace std;
int const N = 2e5 + 10;
int n, sizeBlock;
int arr[N], squareDec[N];

void update(int pos, int val) {
    arr[pos] = val;
    int blockNumber = pos / sizeBlock, l = blockNumber * sizeBlock, mn = INT_MAX;
    do {
        //logic
        mn = min(mn, arr[l++]);
    } while (l % sizeBlock);
    squareDec[blockNumber] = mn;
}

int query(int l, int r) {
    int ans = INT_MAX;
    while (l <= r && l % sizeBlock != 0 && l != 0) {
        // logic
        ans = min(ans, arr[l++]);
    }
    while (l + sizeBlock - 1 <= r) {
        //logic starts
        ans = min(ans, squareDec[l / sizeBlock]);
        //logic ends 
        l += sizeBlock;
    }
    while (l <= r) {
        // logic
        ans = min(ans, arr[l++]);
    }
    return ans;
}

void process() {
    sizeBlock = sqrt(n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (i && i % sizeBlock == 0)
            ++p;
        // logic 
        squareDec[p] = min(squareDec[p], arr[i]);
    }
}
