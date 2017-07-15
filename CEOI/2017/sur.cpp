/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(4);cout << fixed;
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

double a[N],b[N];

double pa[N],pb[N];

double tmp;

double res = 0;

void solve()
{
    cin >> n;

    FOR(i,1,n){
        cin >> a[i] >> b[i];
    }

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);

    FOR(i,1,n){
        pa[i] = pa[i-1] + a[i];
        pb[i] = pb[i-1] + b[i];
    }

    int j = 1;

    FOR(i,1,n){
        while( j<n && pa[i] - (i+j) > pb[j] - (i+j) ){
            res = max(res, min( pa[i] - (i+j), pb[j] - (i+j) ) );
            j++;
        }

        res = max(res, min( pa[i] - (i+j), pb[j] - (i+j) ) );
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
