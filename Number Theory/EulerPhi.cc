const int N = 1e6 + 5;

//smallest prime factor
int SPF[N];

map<int,int> get_divisors(int num) { 
    map<int, int> mp;
    
    while (num > 1) {
        mp[SPF[num]]++;
        num /= spf[num];
    }
    return mp;
}

// phi(n) = number of i in [1...n-1]
// where gcd(i, n) = 1 
int euler_totient(int num) {
    seive();
    if(SPF[num]==num || isprime(num)) 
        return num-1;

    map<int,int> divisors = get_divisors(num);
    int coprimes = 1;
    for(auto &[k, v] : divisors){
        coprimes *= binpower(k, v - 1) * (k - 1);
    }
    return coprimes;
}

/*
Fermat Theorem: - x^(m - 1) mod m = 1 (m is prime and x, m are coprime)
                - x^k mod m = x ^ (k mod (m - 1)) mod m
Euler Theorem: x^phi(m) mod m = 1 (since phi(m) = m - 1 as m is prime)
*/
