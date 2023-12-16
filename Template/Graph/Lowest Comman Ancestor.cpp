#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int N = 3e5 + 9;

int l;
vector<int> g[N], dep;
vector<vector<int>> up;

// preprocessing 
void dfs(int v, int p=0){
    up[v][0] = p;
    dep[v] = dep[p] + 1;
    for(int i=1; i<=l; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(auto &u : g[v]){
        if(u != p){
            dfs(u, v);
        }
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i=l; i>=0; i--){
        if(dep[up[u][i]] >= dep[v]) 
            u = up[u][i];
    }
    if(u == v) return v;
    for(int i=l; i>=0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }   
    return up[u][0];
}

int dist(int u, int v){
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}

int kth(int v, int k){
    assert(k >= 0);
    for(int i=0; i<=l; i++){
        if(k & (1 << i)) v = up[v][i];
    }
    return v;
} 

// kth node from u to v, 0th node = u
int go(int u, int v, int k){
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    // kth node between u and l
    if(dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    // kth node between v and l, node v is 0th
    return kth(v, dep[v] - dep[l] - k); 
}


int32_t main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    l = ceil(log2(n));
    up.assign(N, vector<int>(l+1));
    dep.assign(N, 0);
    dfs(1);
}