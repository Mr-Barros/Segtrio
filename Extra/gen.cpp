#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n'
#define sz(x) (ll) x.size()

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// #define DEBUG
#if defined(DEBUG)
    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>
    void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__) 
#else
    #define dbg(...) (void) 0
#endif

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

void solve() {
    ll n = uniform(0, 10);
    cout << n << ln;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}