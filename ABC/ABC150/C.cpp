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
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> a(n);
    rep(i, n) a[i] = i + 1;
    int c, b;
    int cnt = 0;
    do{
        ++cnt;
        bool okp = true;
        bool okq = true;
        rep(i, n) {
            if(a[i] != p[i]) {
                okp = false;
                break;
            }
        }
        rep(i, n) {
            if(a[i] != q[i]) {
                okq = false;
            }
        }
        if(okp) c = cnt;
        if(okq) b = cnt;
    } while(next_permutation(all(a)));
    cout << abs(b - c) << endl;
    return 0;
}