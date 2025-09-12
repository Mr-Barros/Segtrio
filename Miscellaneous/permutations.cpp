// Roda código a cada permutação dos valores de um vetor. Não gera permutações repetidas. 
// O(N!) amortizado se com valores distintos; provável O(N*N!) com valores repetidos.

v64 v;
sort(v.begin(), v.end()); // garante ordem inicial. Precisa ser não decrescente se não vai gerar apenas um subconiunto das permutações
do
{
    // não usar nada com overhead (set, map...)
}
while (next_permutation(v.begin(), v.end()));
