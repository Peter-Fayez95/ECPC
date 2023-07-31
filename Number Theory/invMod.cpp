const int MOD = 1e9 + 7;

ll inv(ll i) {
  return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}
