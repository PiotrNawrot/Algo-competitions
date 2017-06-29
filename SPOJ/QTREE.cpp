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

#define N (1<<15)
#define LOG 15

int test;

int n;

VI g[N],hld[N];

int h[N],sub_size[N];

int par_hld[N],nr_par_hld[N];

int id[N],hld_id[N],id_in_hld[N];

int load[2*N];

int dp[N][LOG];

int cou,cou1;

int w[N];

PII edg[N];

void pre_dfs(int v,int p){
    h[v] = h[p] + 1;
    sub_size[v] = 1;
    dp[v][0] = p;

    REP(i,g[v].size()){
        int it = g[v][i];
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

    REP(i,g[v].size()){
        int it = g[v][i];
        if (it!=p){
            max_son = max(max_son,mp(sub_size[it],it));
        }
    }

    REP(i,g[v].size()){
        int it = g[v][i];
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
    load[v]=x; v/=2;

    while(v>=1){
        load[v] = max(load[2*v], load[2*v+1]);
        v/=2;
    }

    return;
}

int query(int l,int r){
    if (l>r){
        return 0;
    }
    int res=0;l+=N;r+=N;
    
    res=load[l];

    if (l!=r){
        res=max(res,load[r]);
    }

    while(l/2!=r/2){
        if (l%2==0){
            res=max(res,load[l+1]);
        }
        if (r%2==1){
            res=max(res,load[r-1]);
        }

        l/=2;r/=2;
    }

    return res;
}

int get_sum(int l,int r){
    int lc = lca(l,r);
    int res=0;

    while( hld_id[l]!=hld_id[lc] ){
        res=max(res,query(id[l]-id_in_hld[l]+1,id[l]));
        l = par_hld[l];
    }

    res=max(res,query(id[lc]+1,id[l]));

    while( hld_id[r]!=hld_id[lc] ){
        res=max(res,query(id[r]-id_in_hld[r]+1,id[r]));
        r = par_hld[r];
    }

    res=max(res,query(id[lc]+1,id[r]));

    return res;
}

void solve()
{
    cin >> n;

    FOR(i,1,n-1){
        int a,b,c;
        cin >> a >> b >> c;

        edg[i] = mp(a,b);
        w[i] = c;

        g[a].pb(b);
        g[b].pb(a);
    }

    pre_dfs(1,1);
    do_hld(1,1,++cou,1);    

    FOR(i,1,cou){
        REP(j,hld[i].size()){
            int it = hld[i][j];
            id[it] = ++cou1;
        }
    }

    FOR(i,1,LOG-1){
        FOR(j,1,n){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    FOR(i,1,n-1){
        auto it = edg[i];

        if (dp[it.nd][0] == it.st){
            insert(it.nd,w[i]);
        }else{
            insert(it.st,w[i]);
        }
    }

    while(1){
        string s;
        cin >> s;

        if (s == "DONE"){
            break;
        }else if (s == "CHANGE"){
            int v,x;
            cin >> v >> x;
            w[v] = x;

            auto it = edg[v];

            if (dp[it.nd][0] == it.st){
                insert(it.nd,w[v]);
            }else{
                insert(it.st,w[v]);
            }
        }else if (s == "QUERY" ){
            int v,u;
            cin >> v >> u;
            cout << get_sum(v,u) << endl;
        }
    }

    FOR(i,1,2*N-7){
        load[i]=0;
    }

    FOR(i,1,n){
        h[i] = sub_size[i] = par_hld[i] = nr_par_hld[i] = 0;
        id[i] = id_in_hld[i] = hld_id[i] = w[i] = 0;

        cou=cou1=0;

        FOR(j,0,LOG-1){
            dp[i][j]=0;
        }

        g[i].clear();hld[i].clear();
    }

    return;
}

int32_t main()
{
    boost

    cin >> test;

    while(test--)
    {
        solve();
    }

  return 0;
}
