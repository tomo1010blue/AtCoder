#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define drep(i, n) for(int i = (n) - 1; i >= 0; --i)
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
using G = vector<vector<ll>>;
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
    ll n, w;
    cin >> n >> w;
    vector<ll> dp(200005);
    rep(i, 200005) dp[i] = LINF;
    dp[0] = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        drep(j, 200005 - b) {
            chmin(dp[j+b], dp[j] + a);
        }
    }
    int ans = 0;
    rep(i, 200005) if(dp[i] <= w) ans = i;
    cout << ans << endl;
    return 0;
}