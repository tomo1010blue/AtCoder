#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, r) repl(i, 0, r)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint1000000007;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
template<class T> inline bool chmin(T &a, T b){
    if(a > b){a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a, T b){
    if(a < b){a = b; return true;}
    return false;
}

int main(void) {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll r3 = r1 + 1;
    ll r4 = r1 + 2;
    ll r5 = r1 + 3;
    ll r6 = r1 - 1;
    ll r7 = r1 - 2;
    ll r8 = r1 - 3;
    if(r1 == r2 && c1 == c2) cout << 0 << endl;
    else if(abs(r1 - r2) + abs(c1 - c2) <= 3 || r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) cout << 1 << endl;
    else if((r2 + r1 + c2 - c1) % 2 == 0 && (r2 - r1 + c2 + c1) % 2 == 0) cout << 2 << endl;
    else if(r3 + c1 == r2 + c2 || r3 - c1 == r2 - c2) cout << 2 << endl;
    else if(r4 + c1 == r2 + c2 || r4 - c1 == r2 - c2) cout << 2 << endl;
    else if(r5 + c1 == r2 + c2 || r5 - c1 == r2 - c2) cout << 2 << endl;
    else if(r6 + c1 == r2 + c2 || r6 - c1 == r2 - c2) cout << 2 << endl;
    else if(r7 + c1 == r2 + c2 || r7 - c1 == r2 - c2) cout << 2 << endl;
    else if(r8 + c1 == r2 + c2 || r8 - c1 == r2 - c2) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}