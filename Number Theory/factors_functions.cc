#include <bits/stdc++.h>
using namespace std;

int const N=1e6+1, p=1e9+7;

//smallest prime factor
int spf[N];


// All prime divisors in form [p, k]
// e.g: 9 = [3, 2]
map<int,int> get_divisors(int n) { 
    map<int, int> mp;
    
    while (n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }
    return mp;
}

// Number of factors
// e.g: 10 -> 1, 2, 5, 10 (4) 
int num_factors(int n) {
    //count the number of factors of n
    map<int,int> mp = get_divisors(n);
    int cnt = 1;
    for (auto &[k, v]: mp) {
        cnt*=(v+1);
    }
    return cnt;
}

// Sum of all factors
int sum_factors(int n) {
    //sum the of factors of n
    map<int,int> mp = get_divisors(n);
    int sum = 1;
    for (auto &[k, v]:mp) {
        sum*=(binpower(k, v+1, p)-1)/(k-1);
    }
    return sum;
}

// Product of all factors
int product_factors(int n) {
    //product the of factors of n
    return binpower(n, num_factors(n)/2, p);
}

