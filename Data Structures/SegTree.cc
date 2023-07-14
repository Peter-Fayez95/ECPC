#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

// make sure tree size >= 2n
ll tre[400010];

//construct tree
void construct() {
    
    // initial array
    for (int i=n; i<=2*n-1; i++) cin>>tre[i];

    for (int i=n-1; i>=1; i--) {
        tre[i] = min(tre[2*i], tre[2*i + 1]);
    }
}

// query: sum(a, b)
// operations supported: +,*,^,&,|,gcd,lcm,min,max
// or any associative operation
ll sum(int a, int b) {
    a += (n - 1); b += (n - 1);
    ll minm = INT64_MAX;
    while (a <= b) {
        if (a%2 == 1) minm = min(minm, tre[a++]);
        if (b%2 == 0) minm = min(minm, tre[b--]);
        a /= 2; b /= 2;
    }
    return minm;
}
 

// query: arr[k] = x
void change(int k, ll x) {
    k += (n - 1);
    tre[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tre[k] = min(tre[2*k], tre[2*k+1]);
    }
}