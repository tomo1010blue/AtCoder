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
using G = vector<vector<int> >;
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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int> > is(26);
    rep(i, n) is[s[i]-'a'].insert(i);
    rep(qi, q) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            int i; char c;
            cin >> i >> c;
            --i;
            is[s[i]-'a'].erase(i);
            s[i] = c;
            is[s[i]-'a'].insert(i);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            int ans = 0;
            rep(i, 26) {
                auto it = is[i].lower_bound(l);
                if(it != is[i].end() && *it < r) ++ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}