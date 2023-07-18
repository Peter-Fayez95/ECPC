#include <bits/stdc++.h>
using namespace std;
typedef complex<double> pt;

struct cmp {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
        // sorting in inc. order of first parameter and dec. of second
        // e.g. rank by problems solved and penalty
        if (p1.first==p2.first) return p1.second>p2.second;
        return p1.first<p2.first;
    }
};

struct set_comparator {
    // set custom comparator (set of points)
    bool operator()(pt a, pt b) const {
        return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
    }
};

