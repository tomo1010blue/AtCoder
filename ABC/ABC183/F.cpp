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

struct UnionFind {
    vector<int> d;
    vector<map<int, int>> mp;
    UnionFind(int n=0): d(n,-1), mp(n) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        for(auto p : mp[y]) {
            mp[x][p.fi] += p.se;
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

int main(void) {
    int n, q;
    cin >> n >> q;
    UnionFind t(n);
    rep(i, n) {
        int c;
        cin >> c;
        t.mp[i][c] = 1;
    }
    rep(qi, q) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            t.unite(a, b);
        } else {
            int x, y;
            cin >> x >> y;
            --x;
            x = t.find(x);
            int ans = t.mp[x][y];
            printf("%d\n", ans);
        }
    }
    return 0;
}