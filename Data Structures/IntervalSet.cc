class IntervalSet {
private:
    set<pii> st;

public:
    bool intersect(pii p1, pii p2) {
        return !(p1.second < p2.first || p2.second < p1.first);
    }
    pii merge(pii p1, pii p2) {
        int L = min(p1.first, p2.first);
        int R = max(p2.second, p1.second);
        return {L, R};
    }
    void addToSet(pii pp) {
        auto it = st.insert(pp).first;

        // try to merge with previous
        if (it != st.begin()) {
            if (intersect(*it, *prev(it))) {
                pii uni = merge(*it, *prev(it));
                st.erase(prev(it));
                st.erase(it);
                it = st.insert(uni).first;
            }
        }

        // try to merge with next
        if (it != prev(st.end())) {
            if (intersect(*it, *next(it))) {
                pii uni = merge(*it, *next(it));
                st.erase(next(it));
                st.erase(it);
                st.insert(uni);
            }
        }
    }
};
