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

#define int long long
#define N 100007

int test;

int n;
string s,ss;

VPI g[N];

int dp[N];
int siz[N];

int res;

void dfs(int v,int p,int val){
    siz[v] = 1;

    for(auto it:g[v]){
        if (it.st != p){
            dfs(it.st,v,val);

            if (it.nd&val){
                res += (((siz[it.st] - dp[it.st]) * (siz[v] - dp[v]))%mod) * (val%mod);
                res %= mod;

                res += ((dp[v] * dp[it.st])%mod) * (val%mod);
                res %= mod;
            }else{
                res += (((siz[it.st] - dp[it.st]) * (dp[v]))%mod) * (val%mod);
                res %= mod;

                res += ((dp[it.st] * (siz[v] - dp[v]))%mod) * (val%mod);
                res %= mod;
            }

            siz[v] += siz[it.st];

            if (it.nd&val){
                dp[v] += (siz[it.st] - dp[it.st]);
            }else{
                dp[v] += dp[it.st];
            }
        }
    }

    return;
}

void solve()
{
    cin >> n;

    FOR(i,1,n-1){
        int a,b,c;

        cin >> a >> b >> c;

        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    FOR(i,0,50){
        FOR(j,1,n){
            dp[j] = siz[j] = 0;
        }

        dfs(1,1,(1ll<<i));
    }

    cout << res;

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
