
ll n;
ll len;
v64 v;
v64 b;
v64 lazySum;
v64 lazySet;

void lazy_down(ll blk){
    forn(i,blk*len,(blk+1)*len){
        if(lazySet[blk] != -1){}
        if(lazySum[blk] != 0){}
    }
    lazySum[blk] = 0;
    lazySet[blk] = -1;
}

void solve() {
    len = sqrt(n) + 1;
    b.assign(len, 0);
    lazySum.assign(len, 0);
    lazySet.assign(len, -1);

    forn(i,0,n) cin >> v[i];
    forn(i,0,n) b[i/len] += v[i];

    // queries:
    ll l, r;
    ll bl = l/len;
    ll br = r/len;
    ll sum = 0;
    if(bl == br){
        lazy_down(bl);
        forn(i,l,r+1) {}
    } else {
        lazy_down(bl);
        lazy_down(br);
        forn(i,l,(bl+1)*len) {}
        forn(i,bl+1, br) {}
        forn(i,br*len, r+1) {}
    }
}
