#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct item{
    ll suffix, prefix, maxSum, totSum;
};

struct segTree{
    int size;
    vector<item> vals;
// ######### edit from here #########
    item NEUTRAL_ELEMENT = {0,0,0,0};
    item merge(item l, item r){
      // merge left and right segments
        return{
          max({r.suffix, r.totSum + l.suffix}),
          max({l.prefix, l.totSum + r.prefix}),
          max({l.maxSum, r.maxSum, l.suffix + r.prefix }),
          l.totSum + r.totSum
        };
    }
    item single(int v){
      //set value of a segment of length one
        if(v){
            return {v,v,v,v};
        }
        else{
            return {0, 0, 0, v};
        }
    }
// ########## to here ############
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        vals.resize(2 * size);
    }
    void build(int x, int lx, int rx, vector<int>&a){
        if(rx - lx == 1){
            if(lx < a.size())
                vals[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);
        vals[x] = merge(vals[2 * x + 1], vals[2 * x + 2]);
    }

    void build(vector<int> &a){
        return build(0, 0, size, a);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1) {
            vals[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if( i < m){
            set( i, v, 2 * x + 1, lx, m);
        }
        else{
            set( i, v, 2 * x + 2, m, rx);
        }
       vals[x] = merge(vals[2 * x +1  ], vals[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    item calc(int l, int r, int x, int lx, int rx){

        if( lx >= r  || l >= rx  ) return NEUTRAL_ELEMENT;

        if( lx >= l && rx <= r ) return vals[x];

        int m = (lx + rx ) / 2;
        auto lp = calc(l, r, 2 * x + 1, lx, m);
        auto rp = calc(l, r, 2 * x + 2, m, rx);

        return merge(lp, rp);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

};

int main(){
  int n = 1e5;
  segtree segtr;
  segtr.init(n);
  //set initial values
  //do queries
}
