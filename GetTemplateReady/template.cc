#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define endl '\n'

#define file(in, out)                                                        \
  freopen(in, "r", stdin);                                                     \
  freopen(out, "w", stdout)

#define FIn                                                                    \
  cin.tie(0);                                                                  \
  cout.tie(0);                                                                 \
  ios_base::sync_with_stdio(false)

int tc;
const bool MULTI_TESTS = false;
const string IN = "input.txt";
const string OUT = "output.txt";
const int N = 1e4 + 10;
const ll MOD = 1e9 + 7;

void pre();
void solve(){
    //your code goes here
}
int main() {
    FIn;
    file(IN.c_str(),OUT.c_str());
    tc = 1;
    if(MULTI_TESTS) cin >> tc;
    pre();
    for (int i = 1; i <= tc; i++) {
        // cout << "Case " << i <<": \n";
        solve();
    }
}

void pre(){}
