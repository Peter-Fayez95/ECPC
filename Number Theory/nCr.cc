#include <bits/stdc++.h>
typedef ll long long

const int MAX_N = 100010;
const int p = 1e9 + 7;
int fact[N];

ll binpow(ll n, ll pow, int m) {
    ll res = 1;
    while (pow)
        if (pow & 1)res *= n, res %= m, --pow;
        else n *= n, n %= m, pow >>= 1;
 
    return res;
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
