#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

v64 prefix_function(string s) {
    ll n = s.size();
    v64 pi(n);
    forn (i, 1, n) {
        ll j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) pi[i] = j + 1;
    }
    return pi;
}

v64 kmp(string s, string t) {
    ll n = s.size(), m = t.size();
    string st = s + '#' + t;
    v64 pi = prefix_function(st);
    v64 pos;
    forn (i, 0, n) {
        if (pi[i] == n) pos.push_back(i - 2 * n);
    } 
    return pos;
}

v64 prefix_count(v64 pi) {
    ll n = pi.size();
    v64 ans(n + 1);
    for (ll i = 0; i < n; i++) ans[pi[i]]++;
    for (ll i = n - 1; i > 0; i--) ans[pi[i - 1]] += ans[i];
    for (ll i = 0; i <= n; i++) ans[i]++;
    return ans;
}

void compute_automaton(string s, vector<v64>& aut) {
    s += '#';
    ll n = s.size();
    v64 pi = prefix_function(s);
    aut.assign(n, v64(26));
    forn (i, 0, n) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (i > 0 && c != s[i]) aut[i][c] = aut[pi[i - 1]][c];
            else aut[i][c] = i + (c == s[i]);
        }
    }
}