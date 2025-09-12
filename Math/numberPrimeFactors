// calcula fatores primos de um número em O(sqrt(N))

map<ll,ll> calcPrimeFactors(ll n) {
    map<ll,ll> pfact;
    ll factor = 0;
    ll pot = 0;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            factor = i;
            pot++;
            n /= i; 
        } 
        if(pot > 0){
            pfact[factor] = pot;
            pot = 0;
        } 
    }
    if (n > 1) pfact[n] = 1;
    return pfact;
} 
