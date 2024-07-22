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

// Sorts all suffixes of the given string lexicographically
// Complexity O(n log n)
vector<int> Suffix_Array(string &text) {
    text += '$';
    n = (int) text.size();
    // Order[i] is the start index of the ith lexicographically smallest suffix
    // Class[i] is the lexicographic order of the suffix starting at index i
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
    int k = 0;
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

    // Longest Common Prefix
    // LCP[i] = lcp(suffix of lexicographic order i, suffix of order i + 1)
    vector<int> LCP(n);
    k = 0;

    for (int i = 0; i < n - 1; i++) {
        // suffix starting at index i
        int pi = Class[i];
        int j = Order[pi - 1];

        // lcp[i] = lcp(s[i..], s[j..])
        while(text[i + k] == text[j + k])
            k++;
        LCP[pi - 1] = k;
        k = max(0, k - 1);
    }

    // LCP of the two suffixes starting at index i and index j
    auto get_lcp = [](int i, int j, vector<int> &Class) -> int {
        int pi = Class[i], pj = Class[j];

        // lcp(s[i..n-1], s[j..n-1]) = RMQ(LCP[pi], LCP[pj-1])
        // Using segment tree or sparse table
        return 0;
    };

    // Number of Different Substrings
//    ll sum = 0;
//    for (int i = 0; i < n - 1; i++) {
//        int start_ind = Order[i + 1];
//        sum += n - start_ind - LCP[i] - 1;
//    }
    return Order;
}

// Longest Common Substring in O(|s|+|t| log (|s| + |t|))
string LCSubstr(string &A, string &B) {
    string ss = A + char('$' + 1) + B + '$';
    int nn = ss.length();

    // Calculate vectors Order, Class, and LCP of this string
    // Divide suffixes into two classes 
    // (with class 0 assigned to suffixes belonging to string A)
    vector<bool> C(nn);
    for (int i = 0; i < nn; i++) {
        int start_ind = Order[i];
        int length = (nn - 1) - start_ind;
        if (length <= B.length()) {
            C[i] = 1;
        }
    }
    // maximum common substring
    int maxm = 0; string rslt;
    for (int i = 0; i < nn - 1; i++) {
        if (C[i] != C[i + 1] && LCP[i] > maxm) {
            maxm = LCP[i];
            if (Order[i] >= A.length())
                rslt = B.substr(Order[i] - A.length() - 1, maxm);
            else
                rslt = A.substr(Order[i], maxm);
        }
    }
}
