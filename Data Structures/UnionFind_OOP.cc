#include <bits/stdc++.h>
using namespace std;

class UnionFind { 
    private:
        vector<int> p, rank, setSize; 
        int numSets;
    public:
        UnionFind(int N) {
            p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
            rank.assign(N, 0);
            setSize.assign(N, 1); 
            numSets = N; 
        }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        int numDisjointSets() { return numSets; } 
        int sizeOfSet(int i) { return setSize[findSet(i)]; } 

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return; // i and j are in same set
            int x = findSet(i), y = findSet(j); // find both rep items
            if (rank[x] > rank[y]) swap(x, y);  // keep x ’shorter’ than y
            p[x] = y; // set x under y
            if (rank[x] == rank[y]) ++rank[y];
            setSize[y] += setSize[x]; // combine set sizes at y
            --numSets; // a union reduces numSets
        }
};
