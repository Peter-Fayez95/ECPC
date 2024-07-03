ll hashes[N], p_pow[N];

/* Compute hash function for all string prefixes
 * hash(s) = s[0] + s[1] * p + s[2] * p^2 + ... (mod m) */
void compute_hash(string &str) {
    /* It is reasonable to make p a prime number roughly equal to the
     * number of characters in the input alphabet
     * Frequently Used -> p = 31 (lowercase only)
     *                 -> p = 53 (lower and upper) */
    const int p = 31;
    hashes[0] = 0;
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        hashes[i] = (0LL + hashes[i - 1] + 1LL * ((str[i - 1] - 'a') + 1) * p_pow[i - 1]) % MOD;
        p_pow[i] = (1LL * p_pow[i - 1] * p) % MOD;
    }

    /* m (MOD) should be a large number since the probability of two
     * random strings colliding is about 1 / m. m = 2^64 (for unsigned ll) is not recommended
     * A good choice for m is large prime
     * Frequently used: m = 1e9 + 7, 1e9 + 9, 1e9 + 21 */
}

// Compute hash function for substring
// hash(s[i, j]) = hash(s[1..j]) - hash(s[1..i-1]) * inverse(p^i) (mod m)
ll substring_hash(int i, int j) {
    ll hash = (1LL * (hashes[j] - hashes[i - 1] + MOD) * inv(p_pow[i])) % MOD;
    return hash;
}

/* This hash probability is good for one comparison
 * If we compared a string with 1e6 other strings, the collision probability will become 1e-3
 * And if we want to compare 1e6 different strings with each other,
 * then the probability of at least one collision happening is = 1
 * To get lower probabilities, compute more than one hash (two or more) for each string
 * This is done by using two different p and/or different MOD
 * This is equivalent to having only one hash function with m = 1e18 (for two hashes of m = 1e9)
 * Therefore, When comparing 1e6 strings with each other,
 * the probability that at least one collision happens is now reduced to 1e-6 */

