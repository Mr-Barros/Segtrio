#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ln '\n'

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

const ll MINN = 1;
const ll MAXN = 1e6;

signed main(void) {
    ll n = uniform(MINN, MAXN);
    cout << n << ln;

    return 0;
}