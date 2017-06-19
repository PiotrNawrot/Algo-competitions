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

#define N 13

#define int long long

int test;

int n;

int res;

int fac[N];

char c;

map<string,int>m;

void zrob(string s){
    if (m[s]){
        return;
    }

    m[s]=1;

    int t[N];

    FOR(i,0,10){
        t[i]=0;
    }

    int sum=0;

    REP(i,s.size()){
        sum+=s[i]-'0';
        t[s[i]-'0']++;
    }

    res++;

    if (sum>s.size()){
    }else{
        int sum1=0;
        int cou1=0;

        REP(i,s.size()){
            sum1+=(i+1)*(s[i]-'0');
            cou1+=s[i]-'0';
        }

        if (sum1>s.size()){
            int ile = fac[s.size()];

            ile/=fac[s.size()-cou1];

            REP(i,s.size()){
                ile/=fac[s[i]-'0'];
            }

            res+=ile;
        }else{
            string ss;
            VI g;

            REP(i,s.size()){
                FOR(j,1,s[i]-'0'){
                    g.pb(i+1);
                }
            }

            while(g.size()<s.size()){
                g.pb(0);
            }

            sort(g.begin(),g.end());

            do{
                ss.clear();

                for(auto it:g){
                    char c = it + '0';
                    ss+=c;
                }

                zrob(ss);
            }while(next_permutation(g.begin(),g.end()));
    }
    }

    return;
}

void solve()
{
    string s;
    cin >> s;

    res=0;
    m.clear();

    zrob(s);

    cout << res << endl;

    return;
}

int32_t main()
{
    boost

    fac[0]=1;

    FOR(i,1,10){
        fac[i]=fac[i-1]*i;
    }

    cin >> test;

    FOR(i,1,test)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

  return 0;
}
