// Computes prefix function (pi) in O(n)
// pi[i] is the length of the longest proper prefix of the substring  
// s[0 : i]  which is also a suffix of this substring. 
vector<int> prefix_function(string &str) {
    int n = (int) str.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Count number of occurrences of each prefix in the same string
vector<int> prefix_occurrences(string &str) {
  vector<int> ans(n + 1);
  for (int i = 0; i < n; i++)
      ans[pi[i]]++;
  for (int i = n-1; i > 0; i--)
      ans[pi[i - 1]] += ans[i];
  for (int i = 0; i <= n; i++)
      ans[i]++;
}

/*
To count the number of occurrences of each prefix in another string t
make a new string s + '#' + t and compute its prefix function
but we are only interested in pi[i] for i >= n + 1 and we do the same as
the above function
*/
