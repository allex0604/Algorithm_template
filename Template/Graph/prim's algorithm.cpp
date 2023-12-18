// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
/*
    g[a][b] : 記錄點a到點b之間edge的weight(如無edge : INF)
    selected : 紀錄目前各個vertex有無再MST
    w[a] : 記錄目前MST向外延伸到各個vertex的距離
    nxt[a] : 紀錄各個vertex的parent
    edges : 紀錄被MST中edge被選擇的順序
    ans : MST中edge weight的總和
*/
const int N = 2020;
int g[N][N], selected[N], w[N], nxt[N];

ll Prims(int n, vector< pair<int, int> > &edges){
    ll ans = 0;
    for(int i=1; i<=n; i++) selected[i] = 0, w[i] = 1e9, nxt[i] = -1;
    w[1] = 0;
    for(int i=1; i<=n; i++){
        int u = -1;
        // 找到目前已被選擇的vertex到未被選擇的vertex最短的dist
        for(int j=1; j<=n; j++) if(!selected[j] && (u == -1 || w[j] < w[u])) u = j;
        //NO MST(不連通)
        if(w[u] == 1e9) return - 1; 
        selected[u] = 1;
        ans += w[u];
        //紀錄選擇的edge
        if(nxt[u] != -1)
            edges.emplace_back(u, nxt[u]);
        //新加入的點向外延伸看能否更新到各個點的最短距離
        for(int v=1; v<=n; v++) if(g[u][v] < w[v]) w[v] = g[u][v], nxt[v] = u;  
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > ed;
    ll ans = Prims(n, ed);
    return 0;
}