//simplest form of DSU
//rank herustic
const int N = 2e5;
int p[N], r[N];

void initPandR(){
    for(int i=0;i<N;i++)p[i]=i,r[i]=1;
}

int findSet(int a){
    return p[a] = ( p[a]==a?  a : findSet(p[a]) );
}

void unionSet(int a,int b){
    a=findSet(a),b=findSet(b);
    if(a==b) return;
    if(r[a]==r[b])r[a]++;
    r[a]>r[b] ? p[b]=a :p[a]=b;
}
