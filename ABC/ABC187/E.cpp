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
using P = pair<ll, ll>;
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
    vector<P> edge(n-1);
    vector<vector<ll>> g(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].pb(b);
        g[b].pb(a);
        edge[i] = {a, b};
    }
    vector<ll> depth(n, -1);
    depth[0] = 0;
    vector<ll> q = {0};
    while(q.size()) {
        ll at = q.back();
        q.pop_back();
        for(ll i : g[at]) if(depth[i] == -1) {
            depth[i] = depth[at] + 1;
            q.pb(i);
        }
    }
    vector<ll> s(n);
    int Q;
    cin >> Q;
    while(Q--) {
        ll t, e, x;
        cin >> t >> e >> x;
        auto [a, b] = edge[e-1];
        if(depth[a] > depth[b]) {
            swap(a, b);
            t ^= 3;
        }
        if(t == 1) {
            s[0] += x;
            s[b] -= x;
        }
        else s[b] += x;
    }
    q = {0};
    while(sz(q)) {
        ll at = q.back();
        q.pop_back();
        for(ll i : g[at]) if(depth[at] < depth[i]) {
            s[i] += s[at];
            q.pb(i);
        }
    }
    for(ll i : s) cout << i << endl;
    return 0;
}