// === GEOMETRY: Orientação LEFT/RIGHT/TOUCH e primitivas cross/diff ===
long long getCrossProduct(const v64& v1, const v64& v2){return v1[0]*v2[1]-v1[1]*v2[0];}
v64 getDifference(const v64& v1, const v64& v2){vector<long long> d(2); d[0]=v2[0]-v1[0]; d[1]=v2[1]-v1[1]; return d;}
void solve_orient(){ ll x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
v64 p1={x1,y1},p2={x2,y2},p3={x3,y3}; v64 a=getDifference(p1,p2), b=getDifference(p1,p3);
ll s=getCrossProduct(a,b); if(s>0) cout<<"LEFT\n"; else if(s<0) cout<<"RIGHT\n"; else cout<<"TOUCH\n";}
// === GEOMETRY: Distância entre dois pontos ===
long double getDist(const v64& diff){ return hypotl((long double)diff[0], (long double)diff[1]); }
void solve_dist(){ ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2; v64 d=getDifference({x1,y1},{x2,y2}); cout<<setprecision(7)<<getDist
// === GEOMETRY: Estruturas auxiliares ===
struct Pole { ll x,y; int z; long double ang; long long r2; };
long double polar_angle(ll x,ll y){ long double t=atan2l((long double)y,(long double)x); if(t<0) t+=2.0L*acosl(-1.0L); retur
long double angle_between(ll ax,ll ay,ll bx,ll by){
long double da=hypotl((long double)ax,(long double)ay);
long double db=hypotl((long double)bx,(long double)by);
long double dot=(long double)ax*bx+(long double)ay*by;
long double c=dot/(da*db); if(c>1)c=1; if(c<-1)c=-1; return acosl(c);
}
long long power_of_point(ll x1,ll y1,ll r,ll x2,ll y2){ ll dx=x2-x1, dy=y2-y1; return dx*dx+dy*dy - r*r; }
// === GEOMETRY: Ordenação CCW a partir do semieixo x<=0 ===
typedef long double ld;
const ld eps = 1e-12L;
inline bool eq(ld a, ld b){ return fabsl(a-b)<=eps; }
struct pt{ ld x,y; pt(ld x_=0,ld y_=0):x(x_),y(y_){} ld operator^(const pt& p)const{return x*p.y - y*p.x;} };
inline ld dist2(pt p, pt q){ ld dx=p.x-q.x,dy=p.y-q.y; return dx*dx+dy*dy; }
inline int half(const pt& p){ if(p.y<0) return 0; if(p.y>0) return 1; return (p.x<=0)?0:1; }
inline bool angCmp(const pt& a,const pt& b){int ha=half(a), hb=half(b); if(ha!=hb) return ha<hb; ld cr=(a^b); if(!eq(cr,0))
