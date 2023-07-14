#include <bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> rslt;
vector<int> adj[200005];
stack<int> st;
int n,m,a,b;

void top_sort(int s) {
    if (vis[s]) return;
    vis[s]=1;
    st.push(s);
    for (int ne:adj[s]) {
        top_sort(ne);
    }
    rslt.push_back(s);
    st.pop();
}

int main() {
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i])
            top_sort(i);
    }
    vector<int> ind(n+1);
    reverse(rslt.begin(), rslt.end());
    for (int i=0; i<n; i++) {
        ind[rslt[i]]=i+1;
    }

    // check if possible
    for (int i=1; i<=n; i++) {
        for (int ne:adj[i]) {
            if (ind[ne] <= ind[i]) {
                cout<<"IMPOSSIBLE";
                return;
            }
        }
    }
    for (int ele:rslt) cout<<ele<<" ";
}