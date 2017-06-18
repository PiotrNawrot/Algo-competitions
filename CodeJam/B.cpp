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

#define N 500007

int test;
int n,m;

VPI g[N];

int val[N],ile[N];

BIT czy;

int h[N];

void dfs(int v,int p){
    for(auto it:g[v]){
        int sign = (it.nd > 0) ? -1 : 1;
        int id = abs(it.nd);
        int u = it.st;

        if (h[u]){
            if (h[u] < h[v]){
                ile[id] += sign;
                val[v]++;
                val[u]--;
            }
        }else if (h[u] == 0){
            h[u] = h[v] + 1;
            dfs(u,v);
            val[v]+=val[u];
            ile[id] += sign * val[u];
        }
    }

    return;
}

void solve(){
    cin >> n >> m;

    FOR(i,1,max(m,n)){
        g[i].clear();
        czy[i]=0;h[i]=0;
        val[i]=0;ile[i]=0;
    }

    FOR(i,1,m){
        int a,b;
        cin >> a >> b;

        g[a].pb(mp(b,i));
        g[b].pb(mp(a,-i));
    }

    FOR(i,1,n){
        if (!h[i]){
            h[i] = 1;
            dfs(i,i);
        }
    }

    FOR(i,1,m){
        if (ile[i]==0){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    FOR(i,1,m){
        cout << ile[i] << " ";
    }

    cout << endl;

    return;
}

int32_t main()
{
    boost

    cin >> test;

    FOR(i,1,test){
        cout << "Case #" << i << ": ";
        solve();
    }

  return 0;
}