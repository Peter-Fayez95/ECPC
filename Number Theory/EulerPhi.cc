#include <bits/stdc++.h>
using namespace std;

int const N=1e6+1;

//smallest prime factor
int spf[N];

map<int,int> get_divisors(int num) { 
    map<int, int> mp;
    
    while (num > 1) {
        mp[spf[num]]++;
        num /= spf[num];
    }
    return mp;
}

// phi(n) = number of i in [1...n-1]
// where gcd(i, n) = 1 
int euler_totient(int num) {
    seive();
    if(spf[num]==num || isprime(num)) 
        return num-1;

    map<int,int> divisors = get_divisors(num);
    int coprimes=1;
    for(auto &[k, v]:divisors){
        coprimes *= binpower(k, v-1)*(k-1);
    }
    return coprimes;
}