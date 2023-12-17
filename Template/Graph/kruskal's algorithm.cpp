#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int N = 3e5 + 9;

struct dsu
{
    /*
        par : the parent of each vertex i
        c : connected component number(起始 : 每個點都是一個connected component)
        rnk : height of each subtree
        size : element numbers in each subtree
    */
    vector<int> par, rnk, size;
    int c;
    dsu(int n) : par(n+1), rnk(n+1, 0), size(n+1, 1), c(n){
        for(int i=1; i<n; i++) par[i] = i;
    }
    int find(int i){
        return (par[i] == i) ? i : (par[i] = find(par[i]));
    }
    bool same(int i, int j){
        return (find(i) == find(j));
    }
    int get_size(int i){
        return size[find(i)];
    }
    int count() {return c;}
    int merge(int i, int j){
        if((i = find(i)) == (j = find(j)))
            return -1;
        else --c;
        if(rnk[i] > rnk[j]) swap(i, j);
        par[i] = j; 
        size[j] += size[i];
        if(rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> ed;
    for(int i=1; i<=m; i++){
        int u, v, w; cin >> u >> v >> w;
        ed.push_back({w, u, v});
    }
    sort(ed.begin(), ed.end());
    long long ans = 0;
    dsu d(n);
    for(auto &e : ed){
        auto [w, u, v] = e;
        if(d.same(u, v)) continue;
        ans += w;
        d.merge(u, v);
    }
    cout<<ans<<endl;
}
