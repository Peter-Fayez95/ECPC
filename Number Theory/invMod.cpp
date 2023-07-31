ll inv(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}
