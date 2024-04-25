#include<bits/stdc++.h>
using namespace std;


const int N = 3e5 + 9;

struct ST{
    int t[4 * N];
    static const int inf = 1e9;
    ST(){
        memset(t, 0, sizeof t);
    }

    void build(vector<int> &a, int id, int l, int r){
        if(l == r){
            t[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);

        t[id] = max(t[2 * id], t[2 * id + 1]);
    }

    // 要update的是pos位置的值為x
    void upd(int id, int l, int r, int pos, int x){
        if(pos < l || pos > r) return;
        if(l == r && l == pos){
            t[id] = x;
            return;
        } 

        int mid = (l + r) / 2;
        upd(2 * id, l, mid, pos, x);
        upd(2 * id + 1, mid + 1, r, pos, x);

        t[id] = max(t[2 * id], t[2 * id + 1]);  
    }

    // 搜尋[gl, gr]內的值
    int query(int id, int l, int r, int gl, int gr){
        if(l > gr || r < gl) return -inf;
        if(l >= gl && r <= gr) return t[id];

        int mid = (l + r) / 2;
        int L = query(2 * id, l, mid, gl, gr);
        int R = query(2 * id + 1, mid + 1, r, gl, gr);
        return max(L, R);
    }
}t;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}