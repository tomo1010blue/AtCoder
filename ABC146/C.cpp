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

ll a, b, x;

ll k = 1e18;

ll cnt(ll c) {
    for(int i = 18; ; --i) {
        if(c / k) {
            return i+1;
        }
        k /= 10;
    }
}

bool func(ll c) {
    ll d = cnt(c);
    if(c > x / a) return true;
    if(a * c + b * d > x) return true;
    else false;
}

int main(void)
{
	cin >> a >> b >> x;
    ll l = 0;
    ll r = LINF;
    while(r - l > 1) {
        ll c = (l + r) / 2;
        if(func(c)) {
            r = c;
        }
        else {
            l = c;
        }
    }
    cout << l << endl;
    return 0;
}