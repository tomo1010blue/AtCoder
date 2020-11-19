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
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    int n2 = 1 << n;
    G dp(n2, vector<int>(n, INF));
    G dist(n, vector<int>(n));
    rep(i, n) rep(j, n) {
        int now = abs(x[i] - x[j]);
        now += abs(y[i] - y[j]);
        now += max(0, z[j] - z[i]);
        dist[i][j] = now;
    }
    rep(i, n) {
        if(i == 0) continue;
        dp[1 << i][i] = dist[0][i];
    }
    rep(i, n2) rep(j, n) {
        if(!(i >> j & 1)) continue;
        rep(k, n) {
            if(i >> k & 1) continue;
            chmin(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
        }
    }
    cout << dp[n2 - 1][0] << endl;
    return 0;
}