// BLOCK_SIZE = sqrt(N), 
// if BLOCK_SIZE = 750, set it for 700 or 800 for better runtime
const int BLOCK_SIZE = 500; // N = 2e5
vector<array<int, 3>>queries;
vector<int>ans;
void add(){
    //perform add operation
}

void remove(){
    //perform remove operation
}

<T> get_ans(){
   // compute ans for current query 
}
int main(){
    queries.resize(q);
    ans.resize(q);
    for(int i = 0; i < q; ++i){
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    sort(all(queries), [&](auto const &a, auto const &b)->bool{
        return make_pair(a[0] / BLOCK_SIZE, a[1]) < make_pair(b[0] / BLOCK_SIZE, b[1]);
    });
    int cur_l = 0, cur_r = -1, ind;
    for(auto qq: queries){
        l = qq[0], r = qq[1], ind = qq[2];
//        cout<<l <<' '<<r<<'\n';
        while(cur_l > l){
            --cur_l;
            add(cur_l);
        }
        while(cur_r < r){
            ++cur_r;
            add(cur_r);
        }
        while(cur_l < l){
            remove(cur_l);
            ++cur_l;
        }
        while(cur_r > r){
            remove(cur_r);
            --cur_r;
        }
        ans[ind] = get_ans();
    }
}
