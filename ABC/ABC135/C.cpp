#include <bits/stdc++.h>
#include <atcoder/all>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using P = pair<double, double>;
using G = vector<vector<int>>;
using mint = modint1000000007;
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

int main(void)
{
	int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n+1) {
        if(i != 0) {
            ans += (ll) min(b[i-1], a[i]);
            a[i] = max(0, a[i] - b[i-1]);
        }
        if(i == n) continue;
        ans += (ll) min(a[i], b[i]);
        b[i] = max(0, b[i] - a[i]);
    }
    cout << ans << endl;
    return 0;
}