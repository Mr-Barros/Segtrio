// Dicas base para uso de DP Bitmask. Iteração por cada mask: O(2^n).
// Contar quantos já foram na dp: __builtin_popcount(mask);

ll sz = 1<<n;
v64 dp(sz); //dp padrão tamanho 2^n
dp[0] = 1 //estado inicial

forn(mask,0,sz){ // fazer algo a cada mask. Exemplo (hamiltonian flights):
    forn(i,0,n){
        if (!(mask & (1<<i))) continue;
        forn(j,0,n){
            if((mask & (1 << j))) continue;
            ll nmask = mask | (1 << j);
            // faz algo como:
            dp[nmask] = max(dp[nmask], dp[mask] + 1);
        }
    }
}
