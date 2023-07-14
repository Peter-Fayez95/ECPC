#include <bits/stdc++.h>
using namespace std;


int SPF[1000005];

// O(n log log n)
void sieve() {
    for (int i=3; i<=1000000; i+=2) {
        SPF[i]=i;
    }
    for (int i=2; i<=100000; i+=2) {
        SPF[i]=2;
    }
    for (int i = 3; i * i <= 1000000; i+=2) {
        if (SPF[i]==i) {
            for (int j = i * i; j <= 1000000; j += 2*i)
                SPF[j] = i;
        }
    }
}
