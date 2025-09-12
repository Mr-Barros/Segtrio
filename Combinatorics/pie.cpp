#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

// conta quantos números de 1 a r são divisíveis por pelo menos um
// dos primos em p
ll count_multiples(ll r, v64& p) {
    ll k = p.size();
    ll sum = 0;
    for (ll mask = 1; mask < (1 << k); mask++) {
        ll mult = 1, sig = -1;
        forn (i, 0, k) {
            sig *= (mask & (1 << i)) ? -1 : 1;
            mult *= (mask & (1 << i)) ? p[i] : 1;
        }
        ll cur = r / mult;
        sum += sig * cur;
    }
    return sum;
}