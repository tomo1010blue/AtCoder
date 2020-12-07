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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<ll> sa(n+1), sb(m+1);
    sa[0] = sb[0] = 0;
    rep(i, n) sa[i+1] = sa[i] + (ll) a[i];
    rep(i, m) sb[i+1] = sb[i] + (ll) b[i];
    int ma = upper_bound(all(sa), k) - sa.begin();
    int ans = 0;
    rep(i, ma) {
        int re = k - sa[i];
        int mb = upper_bound(all(sb), re) - sb.begin();
        --mb;
        chmax(ans, i + mb);
    }
    cout << ans << '\n';
    return 0;
}