#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
/*
    g : graph G, gt : transpose of graph, ft : finish time
    idx : 每個點對應到哪個SCC(用root做識別)
    roots : 紀錄每個SCC的root
    adj_scc : 每個SCC相鄰的鄰居有誰(有edge相連)
*/
bool vis[N];
int idx[N];
vector<int> g[N], gt[N], adj_scc[N], ft, roots;

void dfs1(int u){
    vis[u] = 1;
    for(auto &v : g[u])
        if(!vis[v])
            dfs1(v);
    ft.push_back(u);
}

vector<int> comp;
void dfs2(int u){
    comp.push_back(u);
    vis[u] = 1;
    for(auto &v : gt[u])
        if(!vis[v])
            dfs2(v);
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs1(i);
    reverse(ft.begin(), ft.end());
    memset(vis, 0 , sizeof vis);

    int scc = 0;
    for(auto &u : ft){
        if(!vis[u]){
            dfs2(u);
            
            scc++;
            int root = comp.front();
            for(auto &x:comp) idx[x] = root;
            roots.push_back(root);
            
            comp.clear();
        }
    }

    // find adjacency for each scc
    for(int u = 0; u < n; u++){
        for(auto &v : g[u]){
            int root_u = idx[u], root_v = idx[v];
            if(root_u != root_v)
                adj_scc[root_u].push_back(v);
        }
    }
    return 0;
}