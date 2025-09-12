/*
STRINGS/HASH — Polynomial Rolling Hash (double hash)
O que é: representa uma string s[0..n-1] por H = sum(s[i]*B^i) mod M.
Para substring s[l..r] usa H(l,r) = (pref[r] - pref[l-1]) * invB^l (mod M).
Escolhas seguras:
- Bases (B): 911382323, 972663749 ou menores como 911382323 % M; ou aleatório [256..1e6).
- Módulos (M1, M2): 1_000_000_007 e 1_000_000_009 (primos).
- Alfabeto: mapear char -> int (>0). Ex: c = s[i]-'a'+1 para 'a'..'z'.
Operações úteis:
- build_hash(s): prefixos e potências de B
- get(l,r): hash normalizado da substring [l..r]
- concat(hA, lenA, hB): hash(A+B) a partir de hashes de A e B
- LCP via binária usando get(l,r)
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
struct DoubleHash {
static const ll M1 = 1000000007LL;
static const ll M2 = 1000000009LL;
ll B;
vector<ll> p1, p2;
vector<ll> invp1, invp2;
vector<ll> h1, h2;

static ll modpow(ll a, ll e, ll m){
  ll r=1% m; a%=m;
  while(e){ if(e&1) r=(__int128)r*a % m; a=(__int128)a*a % m; e>>=1; }
  return r;
  static ll inv(ll a, ll m){
    return modpow(a, m-2, m);
  }
}

DoubleHash(const string& s, ll base = 0){
  mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
  B = base ? base : (ll)(uniform_int_distribution<ll>(256, 1000000)(rng));
  int n = (int)s.size();
  p1.assign(n+1, 1); p2.assign(n+1, 1);
  invp1.assign(n+1, 1); invp2.assign(n+1, 1);
  h1.assign(n, 0); h2.assign(n, 0);
  ll invB1 = inv(B % M1, M1);
  ll invB2 = inv(B % M2, M2);
  
  for(int i=1;i<=n;i++){
    p1[i] = ( (__int128)p1[i-1] * (B % M1) ) % M1;
    p2[i] = ( (__int128)p2[i-1] * (B % M2) ) % M2;
    invp1[i] = ( (__int128)invp1[i-1] * invB1 ) % M1;
    invp2[i] = ( (__int128)invp2[i-1] * invB2 ) % M2;
  }
  
  auto val = [&](char c)->int{
    if('a'<=c && c<='z') return (c-'a'+1);
    if('A'<=c && c<='Z') return (c-'A'+27);
    if('0'<=c && c<='9') return (c-'0'+53);
    return 100 + (unsigned char)c;
  };
  
  if(n){
    h1[0] = val(s[0]) % M1;
    h2[0] = val(s[0]) % M2;
    for(int i=1;i<n;i++){
      h1[i] = ( ( (__int128)h1[i-1] + (__int128)val(s[i]) * p1[i] ) ) % M1;
      h2[i] = ( ( (__int128)h2[i-1] + (__int128)val(s[i]) * p2[i] ) ) % M2;
    }
  }
}

pair<ll,ll> get(int l, int r) const {
  if(l>r) return {0,0};
  ll x1 = h1[r];
  if(l) x1 = (x1 - h1[l-1] + M1) % M1;
  x1 = (__int128)x1 * invp1[l] % M1;
  ll x2 = h2[r];
  if(l) x2 = (x2 - h2[l-1] + M2) % M2;
  x2 = (__int128)x2 * invp2[l] % M2;
  return {x1, x2};
}

static pair<ll,ll> concat(const pair<ll,ll>& A, int lenA, const pair<ll,ll>& Bhash, int lenB,
ll B, ll M1=1000000007LL, ll M2=1000000009LL){
  auto modpow_ll = [&](ll a, int e, ll m){
    ll r=1% m; a%=m;
    while(e){ if(e&1) r=(__int128)r*a % m; a=(__int128)a*a % m; e>>=1; }
    return r;
  };
  
  ll pA1 = modpow_ll(B % M1, lenA, M1);
  ll pA2 = modpow_ll(B % M2, lenA, M2);
  ll c1 = ( ( (__int128)A.first + (__int128)Bhash.first * pA1 ) ) % M1;
  ll c2 = ( ( (__int128)A.second + (__int128)Bhash.second * pA2 ) ) % M2;
  return {c1, c2};
  }
};
