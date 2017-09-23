/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

#define N 100007

int test;

int n;

VPI g[N];

int t[N];

BIT czyCentro;

VI centros;

VPI layer,pom;

int res[N];

int siz[N];

VI vals[N];

void begDfs(int v,int p){
    siz[v] = 1;

    for(auto it:g[v]){
        if (it.st!=p && czyCentro[it.st] == 0){
            begDfs(it.st,v);
            siz[v] += siz[it.st];
        }
    }

    return;
}

int findCentro(int v,int size,int p){
    int ileMaks = 0;
    int ileSum = 0;

    for(auto it:g[v]){
        if (czyCentro[it.st] == 0 && it.st!=p){
            ileMaks = max(ileMaks,siz[it.st]);
            ileSum += siz[it.st];
        }
    }

    ileMaks = max(ileMaks,size - ileSum - 1);

    if (ileMaks*2 <= size ){
        czyCentro[v] = 1;

        for(auto it:g[v]){
            if (czyCentro[it.st] == 0 && it.st!=p){
                pom.eb(it.st,siz[it.st]);
            }
        }

        if (v!=p){
            pom.eb(p,size - ileSum - 1);
        }

        return v;
    }else{
        for(auto it:g[v]){
            if (czyCentro[it.st] == 0 && it.st!=p && ileMaks == siz[it.st]){
                return findCentro(it.st,size,v);
            }
        }

        return p;
    }
}

void dfs(int v,int p,int dist,int parOfSubtree,int aktCentro){
    vals[parOfSubtree].pb(dist);

    for(auto it:g[v]){
        if (czyCentro[it.st] == 0 && it.st != p){
            if (v == aktCentro){
                dfs(it.st,v,dist+it.nd,it.st,aktCentro);
            }else{
                dfs(it.st,v,dist+it.nd,parOfSubtree,aktCentro);
            }
        }

        if (v == aktCentro){
            for(auto it1:vals[it.st]){
                vals[v].pb(it1);
            }
        }
    }

    if (v == parOfSubtree){
        sort(vals[v].begin(),vals[v].end());
    }

    return;
}

void dfs1(int v,int p,int dist,int parOfAll,int parOfSubtree){
    if (dist > 0){ 
        res[v] += upper_bound(vals[parOfAll].begin(),vals[parOfAll].end(),t[v] - dist) - vals[parOfAll].begin();
        res[v] -= upper_bound(vals[parOfSubtree].begin(),vals[parOfSubtree].end(),t[v] - dist) - vals[parOfSubtree].begin();
    }else{
        res[v] += upper_bound(vals[parOfAll].begin(),vals[parOfAll].end(),t[v] - dist) - vals[parOfAll].begin();
    }

    for(auto it:g[v]){
        if ( czyCentro[it.st] == 0 && it.st != p ){
            if (parOfAll == v){
                dfs1(it.st,v,dist+it.nd,parOfAll,it.st);
            }else{
                dfs1(it.st,v,dist+it.nd,parOfAll,parOfSubtree);
            }
        }       
    }

    return;
}

void solve()
{
    cin >> n;

    FOR(i,1,n){
        cin >> t[i];
    }

    FOR(i,1,n-1){
        int a,b,c;
        cin >> a >> b >> c;

        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    layer.eb(1,n);

    while(layer.size()){
        pom.clear();centros.clear();

        FOR(i,1,n){
            vals[i].clear();
        }

        for(auto it:layer){
        	begDfs(it.st,it.st);
            centros.pb(findCentro(it.st,it.nd,it.st));
        }

        for(auto it:centros){
            dfs(it,it,0,it,it);
            dfs1(it,it,0,it,it);
        }

        swap(layer,pom);
    }

    FOR(i,1,n){
        cout << res[i] << endl;
    }

    return;
}

int32_t main()
{
    boost

    test=1;

    while(test--)
    {
        solve();
    }

  return 0;
}