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
using P = pair<ll, ll>;
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

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 1;
    map<int, vector<int>> mp;
    repl(i, 2, n+1) {
        if(!isPrime(i)) continue;
        int f = 1;
        while(f <= n) {
            mp[i].pb(f);
            f *= i;
        }
    }
    for(auto e : mp) {
        int x = upper_bound(all(e.se), n) - e.se.begin();
        ans *= (ll) e.se[x-1];
    }
    ans += 1;
    cout << ans << '\n';
    return 0;
}