bool StringMatching(string s, string t){
    int m = t.size();
    int n = s.size();
    int j = 0;
    vector <int> pi = prefix_function(t);
    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != t[j]) j = pi[j - 1];
        if(s[i] == t[j]){
            j++;
        }
        if(j == m){
            return true;
        }
    }
    return false;
}
