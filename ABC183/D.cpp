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

int len = 200005;

int main(void)
{
	int n, w;
    cin >> n >> w;
    vector<ll> array(len);
    rep(i, n) {
        int s, t;
        ll p;
        cin >> s >> t >> p;
        array[s] += p;
        array[t] -= p;
    }
    vector<ll> sum(len);
    sum[0] = array[0];
    repl(i, 1, len) {
        sum[i] = sum[i-1] + array[i];
    }
    for(auto e : sum) {
        if(e > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}