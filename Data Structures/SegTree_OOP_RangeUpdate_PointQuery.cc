/*
  VERY IMPORTANT
  Query from [L, R - 1]
*/
 
//change the type of node here
typedef ll item;
 
struct segTree {
    int size;
 
 
    //decide the neutral element
    item NEUTRAL_ELEMENT = 0;
 
    // define the no operation constant to guide you in propagation
    item LAZY = -1;
 
    vector<item> someOperation;
    //change the operation here, (add, max, min, ...)
    // child, parent
    // this is an assignment operation (non-associative) operation
    item merge(item a, item b) {
        //do operation on child first
 
        //parent has no operation
        if(b == LAZY) return a;
 
        // do parent operation after
        return b;
    }
 
    void apply_operation(item &a, item b){
        a = merge(a, b);
    }
 
    void propagate(int x, int lx, int rx){
        if (rx - lx == 1)
            return;
 
        apply_operation(someOperation[2 * x + 1], someOperation[x]);
        apply_operation(someOperation[2 * x + 2], someOperation[x]);
 
        someOperation[x] = LAZY;
 
    }
 
 
    void init(int n) {
        size = 1;
        while (size < n)size <<= 1;
        someOperation.resize(2 * size, NEUTRAL_ELEMENT);
    }
 
    void seg_change(int l, int r, item v, int x, int lx, int rx) {
        propagate(x, lx, rx);
 
        if (lx >= r || l >= rx)
            return;
 
        if (lx >= l && rx <= r) {
            apply_operation(someOperation[x], v);
            return;
        }
 
        int m = lx + (rx - lx) / 2;
        seg_change(l, r, v, 2 * x + 1, lx, m);
        seg_change(l, r, v, 2 * x + 2, m, rx);
 
    }
 
    void seg_change(int l, int r, item v) {
        seg_change(l, r, v, 0, 0, size);
    }
 
    item get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return someOperation[x];
        }
        int m = lx + rx >> 1;
 
        item val;
 
        if (i < m) {
            val = get(i, 2 * x + 1, lx, m);
        } else {
            val = get(i, 2 * x + 2, m, rx);
        }
 
        return merge(val, someOperation[x]);
    }
 
    item get(int i){
        return get(i, 0, 0, size);
    }
 
};
