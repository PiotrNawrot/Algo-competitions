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

// Based on this great solution : https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/#more-108
// Algorithm is basically the same, but i implemented persistent segment trees by myself

#define N 100007
#define LOG 21
#define M ((L+R)/2)

int test;

int n,m;

int val[N],id[N],dp[N][LOG],h[N];

map<int,int>nr,rnr;

VI g[N];

int cou,root,pom;

struct node{
    int l,r,val;
}load[N*LOG];

int new_leaf(int x,int last){
    cou++;
    load[cou].val = last ? load[last].val + 1 : 0;

    return cou;
};

int new_parent(int lef,int rig){
    cou++;

    load[cou].val = load[lef].val + load[rig].val;
    
    load[cou].l = lef;
    load[cou].r = rig;

    return cou;
};

int build(int L,int R){
    if (L==R){
        return new_leaf(L,0);
    }else{
        return new_parent(build(L,M),build(M+1,R));
    }
};

int insert(int v,int x,int L,int R){
    if (L==R){
        return new_leaf(x,v);
    }

    if (x <= M){
        return new_parent(insert(load[v].l,x,L,M),load[v].r);
    }else{
        return new_parent(load[v].l,insert(load[v].r,x,M+1,R));
    }
};

void dfs(int v,int prev){
    id[v] = insert(id[prev],nr[val[v]],1,n);
    dp[v][0] = prev;
    h[v] = h[prev] + 1;

    REP(i,g[v].size()){
        int it = g[v][i];
        if (it!=prev){
            dfs(it,v);
        }
    }

    return;
}

int lca(int x,int y){
    if (h[x] < h[y]){
        swap(x,y);
    }

    FORR(i,LOG-1,0){
        if ( h[x] - (1<<i) >= h[y] ){
            x = dp[x][i];
        }
    }

    if (x==y){
        return y;
    }

    FORR(i,LOG-1,0){
        if (dp[x][i]!=dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }

    return dp[x][0];
}

int query(int a,int b,int c,int d,int L,int R,int k){
    if (L == R){
        return L;
    }else{
        int count = load[load[a].l].val + load[load[b].l].val - load[load[c].l].val - load[load[d].l].val;

        if (count >= k){
            return query(load[a].l,load[b].l,load[c].l,load[d].l,L,M,k);
        }else{
            return query(load[a].r,load[b].r,load[c].r,load[d].r,M+1,R,k-count);
        }
    }
};

void solve()
{       
    cin >> n >> m;

    FOR(i,1,n){
        cin >> val[i];
        nr[val[i]];
    }

    for(map <int, int > :: iterator it = nr.begin(); it != nr.end(); it++){
        nr[(*it).st] = ++pom;
        rnr[pom] = (*it).st;
    }

    FOR(i,1,n-1){
        int a,b;
        cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
    }

    id[0] = build(1,n);
    dfs(1,0);

    FOR(i,1,LOG-1){
        FOR(j,1,n){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    FOR(i,1,m){
        int a,b,c,lc;

        cin >> a >> b >> c;

        lc = lca(a,b);
        cout << rnr[query(id[a],id[b],id[lc],id[dp[lc][0]],1,n,c)] << endl;
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