/*
 check if given substring is palindrome in O(1)
 require O(n) time and O(n) space

 return vector p where
 p(2i) = len of the longest odd-substring centered at i
 p(2i+1) = len of the longest even-substring centered at i
 0-indexed
 */
vector<int> manachar_odd(string s){
    int n = s.size();
    vector<int>p(n + 2);
    s = '$' + s + '^';
    int l = 1, r = 1;

    for(int i = 1; i <= n; ++i){
        p[i] = max(0, min(r - i, p[l + r - i]));
        while(s[i - p[i]] == s[i + p[i]])
            ++p[i];

        if(i + p[i] > r)
            l = i - p[i],
            r = i + p[i];
    }
    return vector<int>(p.begin() + 1, p.end() - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manachar_odd(t + "#");

    for(auto &i: res)--i;

    return vector<int>(begin(res) + 1, end(res) - 1);
}

bool isPalindrome(vector<int>&p, int l, int r){//check if given substring palindrome
    /*
     check at i = (l + r) / 2;
     2i = l + r
     we check at index 2i which equals l + r
     */
    int len = r - l + 1;
    return p[l + r] >= len;
}

