/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

/* Nothing is impossible; impossible itself says "I'm possible" */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
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

#define N (1<<19)
#define LOG 19

int test;

int n;

VI g[N],hld[N];

int h[N],sub_size[N];

int par_hld[N],nr_par_hld[N];

int id[N],hld_id[N],id_in_hld[N];

int load[2*N];

int dp[N][LOG];

int res[N],que[N];

int cou,cou1;

void pre_dfs(int v,int p){
    h[v] = h[p] + 1;
    sub_size[v] = 1;
    dp[v][0] = p;

    for(auto it:g[v]){
        if (it!=p){
            pre_dfs(it,v);
            sub_size[v] += sub_size[it];
        }
    }

    return;
}

void do_hld(int v,int p,int nr,int pos){
    PII max_son = mp(0,0);
    hld[nr].pb(v);
    hld_id[v] = nr;
    id_in_hld[v] = pos;

    for(auto it:g[v]){
        if (it!=p){
            max_son = max(max_son,mp(sub_size[it],it));
        }
    }

    for(auto it:g[v]){
        if (it!=p){
            if (max_son.nd!=it){
                par_hld[it] = v;
                nr_par_hld[it] = nr;

                do_hld(it,v,++cou,1);
            }else{
                par_hld[it] = par_hld[v];
                nr_par_hld[it] = nr_par_hld[v];

                do_hld(it,v,nr,pos+1);
            }
        }
    }

    return;
}

int lca(int x,int y){
    if (h[y]>h[x]){
        swap(x,y);
    }

    FORR(i,LOG-1,0){
        if (h[x] - (1<<i) >= h[y]){
            x = dp[x][i];
        }
    }

    if (x==y){
        return x;
    }

    FORR(i,LOG-1,0){
        if (dp[x][i] != dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }

    return dp[x][0];
}

void insert(int v,int x){
    v = id[v];
    v+=N;
    load[v]+=x; v/=2;

    while(v>=1){
        load[v] = load[2*v] + load[2*v+1];
        v/=2;
    }

    return;
}

int query(int l,int r){
    int res=0;l+=N;r+=N;
    
    res+=load[l];

    if (l!=r){
        res+=load[r];
    }

    while(l/2!=r/2){
        if (l%2==0){
            res+=load[l+1];
        }
        if (r%2==1){
            res+=load[r-1];
        }

        l/=2;r/=2;
    }

    return res;
}

int get_sum(int l,int r){
    int lc = lca(l,r);
    int res=0;

    while( hld_id[l]!=hld_id[lc] ){
        res+=query(id[l]-id_in_hld[l]+1,id[l]);
        l = par_hld[l];
    }

    res+=query(id[lc],id[l]);

    while( hld_id[r]!=hld_id[lc] ){
        res+=query(id[r]-id_in_hld[r]+1,id[r]);
        r = par_hld[r];
    }

    res+=query(id[lc],id[r]);
    res-=query(id[lc],id[lc]);

    return res;
}

void solve()
{
    cin >> n;

    FOR(i,1,n-1){
        int x;
        cin >> x;

        que[i] = x;

        g[x].pb(i);
    }

    pre_dfs(0,0);
    do_hld(0,0,++cou,1);    

    FOR(i,1,cou){
        for(auto it:hld[cou]){
            id[it] = ++cou1;
        }
    }

    FOR(i,1,LOG-1){
        FOR(j,1,n){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
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
