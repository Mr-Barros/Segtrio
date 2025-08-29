// subset sum optimization: O( (k*lim) + (k/64 * (k/lim)) )
// k é a soma máxima dos valores que se pode/quer encontrar.
// com lim = sqrt(k) fica O(ksqrt(k)). lim em geral pode ser um pouco menor pelo bitset dividindo por 64 no lado direito

v64 v;
ll lim = 100;
set<ll> big;
set<ll> small;
v64 cnt(n+1, 0);
bitset<1000001> b;
b[0] = 1;

for(auto val : v){
    if(sz >= lim) big.insert(sz);
    else small.insert(sz);
    cnt[sz] += 1;
}

for(auto sz : small){ // lim * k
    forn(i,0,sz){
        dbg(i);
        ll ct = 0;
        for(ll j = i; j <= k; j += sz){
            dbg(b[j]);
            if(b[j]) ct = cnt[sz];
            else if(ct){
                b[j] = 1;
                ct--;
            }
        }
    }
}

for(auto sz : big){ // k * (k/lim)/64 operacoes
    ll ct = min(cnt[sz], k/sz);
    forn(i,0,ct) b |= (b << sz); 
}
