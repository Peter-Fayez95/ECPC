// __builtin_clz(x): the number of zeros at the beginning of the number
// __builtin_ctz(x): the number of zeros at the end of the number
// __builtin_popcount(x): the number of ones in the number
// __builtin_parity(x): the parity (even or odd) of the number of ones
// __builtin_ffs(x): (the index of the least significant bits of x) + 1
// __lg(x): the index of the highest set bit
// bit_width number of bits needed to represent number

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x); // 19
cout << __builtin_ctz(x); // 4
cout << __builtin_popcount(x); // 5
cout << __builtin_parity(x); // 1
cout << __builtin_ffs(x); // 5
cout << __lg(x); // 12 
cout << bit_width( (unsinged long long) x) //13 
  
// to replace rand
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
shuffle(permutation.begin(), permutation.end(), rng);
