#include<bits/stdc++.h>
using namespace std;


/*
    詳細解說 : 
    (1) https://cp.wiwiho.me/fenwick-tree/
    (2) https://www.csie.ntu.edu.tw/~sprout/algo2021/homework/hand10.pdf
    BIT tree == Binary Indexed Tree, also called Fenwick Tree
    knowledge : 
        lowerbit(i) ==> 指的是把i轉成二進位後，把最低位的1以外的1都變成0， ex. lowerbit(56) == lowerbit(111000) = 1000 = 8
                    ==> lowerbit(i) = i & -i
        father of index i == i - lowerbit(i)
        the range of index i = [p+1, i], p = father
    operation :
    1. build : n update
    2. query : range[1, x] ==> [1, x] 的區間可以拆成 [1, x−lowbit(x)] 和 [x−lowbit(x)+1, x] 
    3. query : range[l, r] 
    4. 單點修改: update every range which includes this element
    ==> 修改它和它祖先的所有右兄弟節點
    5. range [l, r]之間總共修改val(意義不明)

    time complexity :
        query : O(logn)
        update : O(logn)
*/

template<class T>
struct BIT
{
    // a[1] ~ a[m]
    int _n;
    vector<T> t;
    BIT(){}

    BIT(int n){
        _n = n; t.assign(n+1, 0);
    }

    T query(int i){
        T ans = 0;
        for(; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }

    T query(int l, int r){
        return query(r) - query(l-1);
    }

    void upd(int i, T val){
        if(i <= 0) return;
        for(; i <= n; i += (i & -i)) t[i] += val;
    }

    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
};

int32_t main() {

  return 0;
}