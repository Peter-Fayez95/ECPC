// get min on 2d grid for a submatrix of size x * x that starts at i, j
int st[n][m][10];
int a[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
        st[i][j][0]=a[i][j];
    }
}
for(int k=1;k<=log2(min(n,m));k++){
    for(int i=0;i+(1<<k)<=n;i++){
        for(int j=0;j+(1<<k)<=m;j++){
            st[i][j][k]=min(min(st[i][j][k-1],st[i+(1<<(k-1))][j][k-1]),min(st[i][j+(1<<(k-1))][k-1],st[i+(1<<(k-1))][j+(1<<(k-1))][k-1]));
        }
    }
int x = 10 // submatrix of size x * x
int l, r, p=log2(x);
cout << min(min(st[i][j][p],st[i+x-(1<<p)][j+x-(1<<p)][p]),min(st[i][j+x-(1<<p)][p],st[i+x-(1<<p)][j][p])) << endl;
