#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
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
using P = pair<int, int>;
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

int f(int x) {
    int res = 0;
    while(x % 2 == 0) {
        x /= 2;
        ++res;
    } 
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] /= 2;
    int t = f(a[0]);
    rep(i, n) {
        if(f(a[i]) != t) {
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    } 
    m >>= t;
    ll l = 1;
    rep(i, n) {
        l = lcm(l, a[i]);
        if(l > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    m /= l;
    int ans = (m + 1) / 2;
    cout << ans << endl;
    return 0;
}