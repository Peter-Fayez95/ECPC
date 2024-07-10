
void count_sort(vector<int> &Order, vector<int> &Class) {
    vector<int> cnt(n);
    for (auto x : Class) {
        cnt[x]++;
    }
    vector<int> Order_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : Order) {
        int i = Class[x];
        Order_new[pos[i]] = x;
        pos[i]++;
    }
    Order = Order_new;
}

vector<int> Suffix_Array(string &text) {
    text += '$';
    n = (int) text.size();
    vector<int> Order(n), Class(n);
    {
        vector<pair<char, int>> initial(n);
        // k = 0
        for (int i = 0; i < n; i++) {
            initial[i] = {text[i], i};
        }
        sort(all(initial));
        for (int i = 0; i < n; i++) {
            Order[i] = initial[i].second;
        }
        Class[Order[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (initial[i].first == initial[i - 1].first) {
                Class[Order[i]] = Class[Order[i - 1]];
            }
            else {
                Class[Order[i]] = Class[Order[i - 1]] + 1;
            }
        }
    }
    k = 0;
    while((1 << k) < n) {
        // Transition k -> k + 1
        for (int i = 0; i < n; i++) {
            Order[i] = (Order[i] - (1 << k) + n) % n;
        }
        count_sort(Order, Class);

        vector<int> C_new(n);
        C_new[Order[0]] = 0;
        for (int i = 1; i < n; i++) {
            pii prev = {Class[Order[i - 1]], Class[(Order[i - 1] + (1 << k)) % n]};
            pii now = {Class[Order[i]], Class[(Order[i] + (1 << k)) % n]};
            if (prev == now) {
                C_new[Order[i]] = C_new[Order[i - 1]];
            }
            else {
                C_new[Order[i]] = C_new[Order[i - 1]] + 1;
            }
        }

        Class = C_new, k++;
    }
    return Order;
}
