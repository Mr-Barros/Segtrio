// Faz o sieve calculando a função fi. O(N*log(N)).
struct sieveCell {
    ll maxDiv;
    ll fi;
    set<ll> distinctPrimes;
    sieveCell(ll max, ll f){maxDiv = max; fi = f; distinctPrimes = {};}
};

vector<sieveCell> makeSieve(){
    vector<sieveCell> sv(N+1, sieveCell(-INF, -INF));
    v64 primes;
    forn(i, 2, N+1){
        if(sieve[i].maxDiv == -INF){
            primes.push_back(i);
            sv[i].maxDiv = i;
            sv[i].fi = i-1;
            sv[i].distinctPrimes = {i};
        }
        for(ll prime : primes){
            if(prime > sv[i].maxDiv) break;
            if(i*prime > N) break;
            sv[i*prime].maxDiv = i;
            sv[i*prime].distinctPrimes = sv[i].distinctPrimes;
            sv[i*prime].distinctPrimes.insert(prime);
            sv[i*prime].fi = i*prime;
            for(ll distPrime : sv[i*prime].distinctPrimes){
                sv[i*prime].fi = (sv[i*prime].fi - sv[i*prime].fi/distPrime);
            }
        }
    }
    return sv;
}
