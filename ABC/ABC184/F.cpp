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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> u, v;
    u = v = {0};
    rep(i, n) {
        for(int j = u.size() - 1; j >= 0; --j) {
            u.pb(u[j] + a[i]);
        }
        swap(u, v);
    }
    sort(all(u));
    ll ans = 0;
    for(ll x : v) {
        if(x > t) continue;
        int si = upper_bound(all(u), t - x) - u.begin();
        chmax(ans, x + u[si-1]);
    }
    cout << ans << endl;
    return 0;
}