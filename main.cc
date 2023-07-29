#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define ll long long

#define file \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout);

#define OJudge(in, out) \
  freopen(in, "r", stdin); \
  freopen(out, "w", stdout); 

#define FIn \
  cin.tie(0); \
  cout.tie(0); \
  ios_base::sync_with_stdio(0);

#define endl "\n"

const int N = 200005;
const ll mod = 1e9 + 7;

typedef double T;
typedef complex<T> pt;
// #define x real()
// #define y imag()

int tc, n;
const T pi = 3.1415926535897;

void pre(); 
void solve() {
  
}


int main() {
  FIn;
  file; 
  // OJudge("", "");
  tc = 1;
  cin >> tc;
  pre();
  for (int i=1; i<=tc; i++) {
    // cout << "Case " << i << ": ";
    solve();
  }
}

void pre() {
  
}

