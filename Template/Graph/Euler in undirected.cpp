#include<bits/stdc++.h>
using namespace std;

/*
    g[u][j] = {v, i} ==> u <-> v , edge id = i
    done[u] = 目前走完vertex u幾條邊了
    vis[i] = 有無visit edge e_i
    ans = euler path(cycle)
    euler path : 此graph連通(connected)且至多兩個vertex的degree是奇數
    euler cycle : 此graph連通(connected)且每一個vertex的degree都是偶數
*/
vector<vector<pair<int, int>>> g;
vector<bool> vis, ver_vis;
vector<int> ans, done;
void dfs(int u){
    ver_vis[u] = 1;
    while(done[u] < g[u].size()){
        auto e = g[u][done[u]++];
        if(vis[e.second]) continue;
        vis[e.second] = 1;
        dfs(e.first);
    }
    ans.push_back(u);
}

bool solve(int n, int m, vector<int> &deg){
    int odd = 0, root = 0;
    for(int i = 1; i <= n; i++){
       if(deg[i] % 2 == 1){
           odd++;
           root = i;
       }
    }
    //if(odd > 2) return 0; // without euler path
    if(odd > 0) return 0; // without euler circuit
    if(root == 0){
        for(int i=1; i<=n; i++) if(deg[i]) root = i;
        if(root == 0) return 1; // empty graph
    }    
    vis = vector<bool>(m+1, 0);
    ver_vis = vector<bool>(n+1, 0);
    done = vector<int>(n+1, 0);
    dfs(root);
    for(int i=1; i<=n; i++) if(!ver_vis[i]) return 0; // connectivity
    reverse(ans.begin(), ans.end());
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    g = vector<vector<pair<int, int>>>(n + 1);
    vector<int> deg(n+1, 0);
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        deg[u]++, deg[v]++;
    } 
    if(solve(n, m, deg)){
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        ans.clear();
    }
    return 0;
}