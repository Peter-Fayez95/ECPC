const int MAX_N = 100010, p = 1e9 + 7;
int fact[N];

ll binpow(ll base, ll e, ll mod) {
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

ll inv(ll a) {
    // inverse mod
    return binpow(a, p-2, p);
}

ll nCr(ll n, ll r) {
    // nCr mod p
    if (n < r) return 0;
    return ((fact[n]*inv(fact[r])) % p * inv(fact[n-r])) % p;
}

ll nPr(ll n, ll r) {
    return ((fact[n] * inv[n - r])) % p;
}

void pre() {
    // n! mod p
    fact[0]=1;
    for (int i=1; i <= MAX_N; i++) {
        fact[i]= (1LL * fact[i-1] * i)%p;
    }
}
/*
nCr propreties
    nCr = (n-1)Cr + (n-1)C(r-1)
    nCr = (n / r) * (n-1)C(r-1)
    Summation(over all) nCr = pow(2,n)
    Summation(over odd) = summation(over even) = pow(2, n-1)
    Summation(0,n) (2n+1)Ci = pow(2, 2n)
    Summation(n,2n-1) iCn = (2n)C(n+1)
*/
