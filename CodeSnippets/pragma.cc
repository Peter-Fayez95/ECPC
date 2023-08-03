// Optimization Levels
/*
* -O0 defult, optimize: for compilation time
* -O1 low optimization, almost not affecting compilation time
* -O2 all optimizations, that have little to no negative side effects
* -O3 very aggressive, enables all correct optimizations implemented in GCC
* -Ofast  all of O3 plus more, floating-point operations my be rearranged and the result is off by a few bits in mantissa
*/
#pragma GCC optimize("O3")

// based on architucture
// avx2, avx, sse4.2, sse4.1, sse4, sse3, sse2, sse
// for bit manipulation, bmi2 not a subset of bmi
//abm, bmi, bmi2
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

// a general way to inform the compiler that there are no dependencies between the loop iterations:
void sum(int *a, int *b, int *c, int n) {
    #pragma GCC ivdep
    for (int i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}

// Likeliness of branches can be hinted by [[likely]] and [[unlikely]] attributes in if-s and switch-es:
int factorial(int n) {
    if (n > 1) [[likely]]
        return n * factorial(n - 1);
    else [[unlikely]]
        return 1;
}

// constexpr; if it is called by passing constants its value is guaranteed to be computed during compile time:
constexpr int fibonacci(int n) {
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
static_assert(fibonacci(10) == 55);




