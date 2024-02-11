#include<bits/stdc++.h>
using namespace std;

vector<int> build_lps(string t){
    int sz = t.size();
    vector<int> lps(sz);
    lps[0] = 0;
    
    for(int i=1, j; i<sz; i++){
        j = lps[i - 1];
        while(j > 0 && t[i] != t[j])
            j = lps[j - 1];
            
        if(t[i] == t[j])
            j++;
        lps[i] = j;
    }
    
    // change to failure
    for(int i=sz-1; i > 0; i--)
        lps[i] = lps[i-1];
    lps[0] = -1;
    return lps;
}

void kmp(string s, string t){
    int sz = s.size(), tz = t.size();
    int i = 0, j = 0;
    vector<int> lps = build_lps(t);
    while(i < sz){
        if(j == tz-1 && s[i] == t[j]){
            cout<<"found pattern at "<<i-j<<endl;
            j = lps[j];
        }
        if(s[i] == t[j])
            i++, j++;
        else{
            j = lps[j];
            if(j == -1)
                i++, j++;
        }
    }
}

int main ()
{
  string s = "abababcabaa";
  string t = "ababcabaa";
  kmp(s, t);
  return 0;
}