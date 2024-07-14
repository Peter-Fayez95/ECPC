/*
  VERY IMPORTANT
  Query from [L, R - 1]
*/

//change the the type of node here
typedef ll item;

struct segTree {
    int size;
    vector<item> someOperation;

    //decide the neutral element
    item NEUTRAL_ELEMENT = 0;

    //change the operation here, (add, max, min, ...)
    item merge(item a, item b) {
        return a + b;
    }

    item single(item v) {
        return v;
    }

    void init(int n) {
        size = 1;
        while (size < n)size <<= 1;
        someOperation.resize(2 * size);
    }

    void seg_change(int l, int r, item v, int x, int lx, int rx) {
        if (lx >= r || l >= rx) {
            return;
        }
        if (lx >= l && rx <= r) {
            someOperation[x] = merge(someOperation[x], v);
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
