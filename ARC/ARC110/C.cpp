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
#define sz(x) ((int) (x).size())
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    bool ng = false;
    rep(i, n) {
        if(p[i] == i+1) ng = true;
    }
    if(ng) {
        cout << -1 << '\n';
        return 0;
    }
    ll cost = 0;
    rep(i, n) cost += (ll) abs(p[i] - i - 1);
    if(cost != (ll) 2 * (ll) (n - 1)) {
        cout << -1 << '\n';
        return 0; 
    }
    vector<P> q(n);
    vector<int> ans;
    rep(i, n) {
        q[i].fi = p[i];
        q[i].se = i + 1;
    }
    sort(all(q));
    for(auto e : q) {
        if(e.fi >= e.se) continue;
        for(int j = e.se - 1; j >= e.fi; --j) {
            ans.pb(j);
        }
    }
    if(sz(ans) != n-1) {
        cout << -1 << '\n';
        return 0;
    }
    for(auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}