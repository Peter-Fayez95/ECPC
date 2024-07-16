const int N = 1e6 + 5;
// O(n log log n)
void sieve() {
    for (int i = 3; i < N; i += 2) {
        SPF[i] = i;
    }
    for (int i = 2; i < N; i += 2) {
        SPF[i] = 2;
    }
    for (int i = 3; i * i < N; i += 2) {
        if (SPF[i] == i) {
            for (int j = i * i; j < N; j += 2 * i)
                SPF[j] = i;
        }
    }
}
