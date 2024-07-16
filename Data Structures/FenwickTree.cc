// original array, tree array
int n, q;
ll arr[100005], tre[100005];

//tree construction O(n)
void construct(int k, ll x) {
    while (k <= n) {
        tre[k] += x;
        k += k & -k;
    }
}

// get cumulative sum (segment [1, k])
// sum(a, b) = sum(b) - sum(a-1)
ll sum(int k) {
    ll s = 0;
    while (k >= 1) {
        s += tre[k];
        k -= (k&(-k));
    }
    return s;
}

// query: add x to arr[k]
// change x to your need for different functions
// e.g. x = -arr[k] (query: arr[k] = 0)
void add(int k, ll x) {
    arr[k] += x;
    while(k <= n) {
        tre[k] += x;
        k += k&-k;
    }
}

int main() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        tre[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        construct(i, arr[i]);
    }

    // process queries O(log n)
}
