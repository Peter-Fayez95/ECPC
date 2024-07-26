typedef int item;

struct segTree {
    int size;
    vector<item> updateOperation;
    vector<item> getOperation;
    
    //Change these parameters
    item NEUTRAL_ELEMENT = 0;
    item LAZY = LONG_LONG_MAX;


    // Change update query here
    // assign b to segment, new sum will be b * seg_len
    item operation_update(item a, item b, int len) {
        // no operation to apply
        if(b == LAZY) return a;

        //apply operation
        return b * len;

    }

    // change get query here
    item operation_get(item a, item b){
        return a + b;
    }

    void apply_operation(item &a, item b, int len){
        a = operation_update(a, b, len);
    }


    void init(int n){
        size = 1;
        while (size < n)size <<= 1;
        updateOperation.resize(2 * size, 0);
        getOperation.resize(2 * size, 0);
    }

    void build(int x, int lx, int rx, vector<int> &a){
        if(rx - lx == 1) {
            if (lx < a.size())
                getOperation[x] = a[lx];
            return;
        }

        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, a);
        build(2 * x + 2, m, rx, a);

        getOperation[x] = operation_get(getOperation[2 * x + 1], getOperation[2 * x + 2]);
    }

    void build(vector<int> &a){
        build(0, 0, size, a);
    }
    
    void propagate(int x, int lx, int rx){
        if(rx - lx == 1)
            return;

        int m = (lx + rx) / 2;
        apply_operation(getOperation[2 * x + 1], updateOperation[x], m - lx);
        apply_operation(getOperation[2 * x + 2], updateOperation[x], rx - m);

        apply_operation(updateOperation[2 * x + 1], updateOperation[x], 1);
        apply_operation(updateOperation[2 * x + 2], updateOperation[x], 1);

        updateOperation[x] = LAZY;

    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
            return;

        if (lx >= l && rx <= r) {
            apply_operation(updateOperation[x], v, 1);
            apply_operation(getOperation[x], v, rx - lx);
            return;
        }

        int m = lx + (rx - lx) / 2;
        update(l, r, v, 2 * x + 1, lx, m);
        update(l, r, v, 2 * x + 2, m, rx);

        getOperation[x] = operation_get(getOperation[2 * x + 1], getOperation[2 * x + 2]);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }

    item get(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);

        if (lx >= r || l >= rx)
            return NEUTRAL_ELEMENT;

        if (lx >= l && rx <= r)
            return getOperation[x];

        int m = lx + rx >> 1;

        item val1, val2;
        val1 = get(l, r, 2 * x + 1, lx, m);
        val2 = get(l, r, 2 * x + 2, m, rx);

        auto rslt = operation_get(val1, val2);
        return rslt;

    }

    item get(int l, int r){
        return get(l, r, 0, 0, size);
    }

};
