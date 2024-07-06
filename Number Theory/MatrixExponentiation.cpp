//change data type if needed
typedef vector<int> vT;
typedef vector<vector<int>> vvT;

struct Matrix_Expo{

    vvT base;
    int n;
    int mod;
    explicit Matrix_Expo(vvT &b, int m){
        base = b;
        n = b.size();
        mod = m;
    }

    vvT matrix_mul(vvT &a, vvT &b){

        vvT c = vvT(n, vT(n));

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                for(int k = 0; k < n; ++k){
                  c[i][j] += (1ll * a[i][k] * b[k][j]) % mod;
                  c[i][j] %= mod;
                }

        return c;
    }

    vvT expo(ll pow){
        vvT rslt(n, vT(n));
        // Identity matrix, change if needed
        for(int i = 0; i < n; ++i)
            rslt[i][i] = 1;

        while(pow > 0){
            if(pow & 1)
                rslt = matrix_mul(rslt, base);
            base = matrix_mul(base, base);
            pow >>= 1;
        }
        return rslt;
    }

};
