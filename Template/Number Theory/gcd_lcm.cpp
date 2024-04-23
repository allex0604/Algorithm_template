#include <bits/stdc++.h>

using namespace std;

// using euclid's algorithm
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    
    int a = 100, b = 30;
    if(a < b) cout << gcd(b, a) << endl;
    else cout << gcd(a, b) << endl;

    if(a < b) cout << lcm(b, a) << endl;
    else cout << lcm(a, b) << endl;
    return 0;
}