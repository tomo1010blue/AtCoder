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

const ll MX = 10000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string t;
    cin >> t;
    if(n == 1) {
        if(t == "1") {
            cout << (ll) 2 * MX << '\n';
            return 0;
        }
        cout << MX << '\n';
        return 0;
    }
    if(n == 2) {
        if(t == "00") cout << 0 << '\n';
        else if(t == "10" || t == "11") cout << MX << '\n';
        else cout << MX - 1 << '\n';
        return 0;
    }
    if(t[0] == '0' && t[1] == '0') {
        cout << 0 << '\n';
        return 0;
    }
    if(t[0] == '0') {
        bool ng = false;
        rep(i, n) {
            if(i % 3 == 0) {
                if(t[i] != '0') ng = true;
            } else {
                if(t[i] != '1') ng = true;
            }
        }
        if(ng) {
            cout << 0 << '\n';
            return 0;
        }
        int cy = (n-1) / 3;
        if((n-1) % 3 == 0) {
            cout << MX - cy << '\n';
            return 0;
        }
        cout << MX - cy - 1 << '\n';
        return 0;
    }
    if(t[1] == '0') {
        bool ng = false;
        rep(i, n) {
            if(i % 3 == 1) {
                if(t[i] != '0') ng = true;
            } else {
                if(t[i] != '1') ng = true;
            }
        }
        if(ng) {
            cout << 0 << '\n';
            return 0;
        }
        int cy = (n-2) / 3;
        if((n-2) % 3 == 0) {
            cout << MX - cy << '\n';
            return 0;
        }
        cout << MX - cy - 1 << '\n';
        return 0;
    }
    if(t[1] == '1') {
        bool ng = false;
        rep(i, n) {
            if(i % 3 == 2) {
                if(t[i] != '0') ng = true;
            } else {
                if(t[i] != '1') ng = true;
            }
        }
        if(ng) {
            cout << 0 << '\n';
            return 0;
        }
        int cy = n / 3;
        if(n % 3 == 0) {
            cout << MX - cy + 1 << '\n';
            return 0;
        }
        cout << MX - cy << '\n';
        return 0;
    }
    return 0;
}