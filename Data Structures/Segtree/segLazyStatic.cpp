// Static seglazy
// 4*n memory

struct lazy {
    ll add = 0;
    ll set = -INF;
    
    void compose(const lazy& o) {
        if (o.set != -INF) {
            set = o.set;
            add = 0;
        }
        if (o.add != 0) {
            if (set != -INF) set += o.add;
            else add += o.add;
        }
    }
};

struct node {
    ll val = 0;
    
    static node comb(const node& a, const node& b) {
        return {min(a.val, b.val)};
    }

    void resolve(const lazy& lz, ll l, ll r) {
        if (lz.set != -INF) val = lz.set;
        if (lz.add != 0) val += lz.add;
    }
};

const node neutral = {INF};

struct StaticTree {
    ll n;
    vector<node> tree;
    vector<lazy> lz;

    StaticTree(const v64& a) : n(sz(a)) {
        tree.resize(4 * n + 1);
        lz.assign(4 * n + 1, {0, -INF});
        build(a, 1, 0, n - 1);
    }

    void build(const v64& a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = {a[tl]};
        } else {
            ll tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            tree[v] = node::comb(tree[2 * v], tree[2 * v + 1]);
        }
    }

    void push(ll v, ll tl, ll tr) {
        if (lz[v].set != -INF || lz[v].add != 0) {
            tree[v].resolve(lz[v], tl, tr);
            if (tl != tr) {
                lz[2 * v].compose(lz[v]);
                lz[2 * v + 1].compose(lz[v]);
            }
            lz[v] = {0, -INF};
        }
    }

    node update(ll lq, ll rq, lazy x, ll v = 1, ll tl = 0, ll tr = -1) {
        if (tr == -1) tr = n - 1; 
        push(v, tl, tr);
        if (lq > tr || rq < tl) return tree[v];
        if (lq <= tl && tr <= rq) {
            lz[v].compose(x);
            push(v, tl, tr);
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return tree[v] = node::comb(update(lq, rq, x, 2 * v, tl, tm),
                                    update(lq, rq, x, 2 * v + 1, tm + 1, tr));
    }

    node query(ll lq, ll rq, ll v = 1, ll tl = 0, ll tr = -1) {
        if (tr == -1) tr = n - 1; 
        push(v, tl, tr);
        if (lq > tr || rq < tl) return neutral;
        if (lq <= tl && tr <= rq) return tree[v];
        ll tm = (tl + tr) / 2;
        return node::comb(query(lq, rq, 2 * v, tl, tm),
                          query(lq, rq, 2 * v + 1, tm + 1, tr));
    }
};


// Boas funcoes a se adicinoar:
// Encontra a primeira posição j em [lq, rq] tal que tree[j].val <= val
// Nota: como sua seg é de MIN, usamos <= val para encontrar elementos "pequenos"
ll get_left(ll lq, ll rq, ll val, ll v = 1, ll tl = 0, ll tr = -1) {
    if (tr == -1) tr = n - 1;
    push(v, tl, tr);
    
    // Se o intervalo está fora ou o valor mínimo aqui é maior que o alvo, impossível
    if (lq > tr || rq < tl || tree[v].val > val) return -1;
    if (tl == tr) return tl;

    ll tm = (tl + tr) / 2;
    ll x = get_left(lq, rq, val, 2 * v, tl, tm);
    if (x != -1) return x;
    return get_left(lq, rq, val, 2 * v + 1, tm + 1, tr);
}

// Encontra a última posição j em [lq, rq] tal que tree[j].val <= val
ll get_right(ll lq, ll rq, ll val, ll v = 1, ll tl = 0, ll tr = -1) {
    if (tr == -1) tr = n - 1;
    push(v, tl, tr);

    if (lq > tr || rq < tl || tree[v].val > val) return -1;
    if (tl == tr) return tl;

    ll tm = (tl + tr) / 2;
    ll x = get_right(lq, rq, val, 2 * v + 1, tm + 1, tr);
    if (x != -1) return x;
    return get_right(lq, rq, val, 2 * v, tl, tm);
}

// Para seg de SOMA (precisaria mudar o node::comb para a + b)
// Encontra o maior j tal que a soma de [lq, j] seja o limite val
ll lower_bound(ll lq, ll& val, ll v = 1, ll tl = 0, ll tr = -1) {
    if (tr == -1) tr = n - 1;
    push(v, tl, tr);

    if (tr < lq) return n;
    
    // Se o intervalo atual está contido e a soma total dele é menor que val
    if (lq <= tl && tree[v].val < val) {
        val -= tree[v].val;
        return n;
    }
    if (tl == tr) return tl;

    ll tm = (tl + tr) / 2;
    ll x = lower_bound(lq, val, 2 * v, tl, tm);
    if (x != n) return x;
    return lower_bound(lq, val, 2 * v + 1, tm + 1, tr);
}
