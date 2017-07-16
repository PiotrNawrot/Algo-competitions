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

#define N 50007

int test;

string s,res;

short a[N],b[N];

int n,m;

void solve()
{
    cin >> n >> m;

    cin >> s;reverse(s.begin(),s.end());

    FOR(i,1,n){
        a[i] = s[i-1] - '0';
    }

    if (s == "0"){
        cout << 0;
        return;
    }

    cin >> s;reverse(s.begin(),s.end());

    if (s == "0"){
        cout << 0;
        return;
    }

    FOR(i,1,m){
        b[i] = s[i-1] - '0';
    }

    int tmp = 0;

    FOR(i,1,n+m-1){
        for(int j = max(1,i-n+1); j<= min(i,m); j++){
            tmp += b[j] * a[i-j+1];
        }

        char c = (tmp % 10) + '0';
        res += c;

        tmp /= 10;
    }

    if (tmp){
        char c = (tmp % 10) + '0';
        res += c;
    }

    reverse(res.begin(),res.end());

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
