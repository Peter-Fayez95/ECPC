#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define all(x) x.begin(), x.end()
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
const int N = 1e4 + 10;
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
