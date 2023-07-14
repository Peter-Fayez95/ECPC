#include <bits/stdc++.h>
#define ll unsigned long long

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e >>= 1LL;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (ll)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { 
    // true if n is prime.

    set<int> st {2, 3, 5, 13, 19, 73, 193, 407521, 299210837};

    if (n < 2)
        return false;

    if (st.count(n)) {
        return true;
    }

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}