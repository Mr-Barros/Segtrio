// Mo Algorithm: O((N + Q) * sqrt(N))

ll len;
struct Query {
    ll l, r, i, k;
    bool operator<(Query other) const {
        ll bl = l/len;
        ll o_bl = other.l/len;
        if(bl != o_bl) return bl < o_bl;
        if(bl & 1) return r > other.r;
        else return r < other.r;
    }
    Query(ll l_, ll r_, ll i_, ll k_) : l(l_), r(r_), i(i_), k(k_) {}
};


inline void remove(ll idx){}
inline void add(ll idx) {}

void solve() {
    len = sqrt(n);

    vector<Query> queries;
    forn(i,0,m){
        ll v, k; cin >> v >> k;
        v--;
        queries.push_back(Query(ranges[v].first,ranges[v].second, i, k));
    }
    sort(queries.begin(), queries.end());

    v64 ans(m);
    for(auto q : queries){
        while(cl > q.l) add(--cl);
        while(cr < q.r) add(++cr);
        while(cl < q.l) remove(cl++);
        while(cr > q.r) remove(cr--);
        ans[q.i] = //logica
    }
    forn(i,0,m) cout << ans[i] << ln;
}
