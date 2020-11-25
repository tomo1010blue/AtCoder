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
using mint = modint998244353;
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
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    rep(i, k) cin >> l[i] >> r[i];
    vector<mint> dp(n+1), dpsum(n+1);
    dp[1] = 1;
    repl(i, 1, n+1) {
        rep(j, k) {
            if(i - l[j] < 1) continue;
            int s = i - l[j];
            int t = max(1, i - r[j]);
            dp[i] += dpsum[s] - dpsum[t-1];
        }
        dpsum[i] = dpsum[i-1] + dp[i];
    }
    cout << dp[n].val() << endl;
    return 0;
}