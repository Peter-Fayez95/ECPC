#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;

using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order((int)k) returns iterator of the kth element
// order_of_key((T)key) returns the number of elements less than this key

#define ll long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#define file                                                                   \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout)

#define OJudge(in, out)                                                        \
  freopen(in, "r", stdin);                                                     \
  freopen(out, "w", stdout)

#define FIn                                                                    \
  cin.tie(0);                                                                  \
  cout.tie(0);                                                                 \
  ios_base::sync_with_stdio(false)

int tc;
const ll N = 1e4 + 10;
const ll mod = 1e9 + 7;

void pre();

void solve() {}

int main() {
  FIn;
#ifndef ONLINE_JUDGE
  file;
#endif
  //    OJudge(".in",".out");

  tc = 1;
  //    cin >> tc;
  pre();
  for (int i = 1; i <= tc; i++) {
    // cout << "Case " << i <<": \n";
    solve();
  }
}

void pre() {}
