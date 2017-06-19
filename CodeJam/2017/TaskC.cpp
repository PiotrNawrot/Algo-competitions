/* Eat a live frog first thing in the morning,
   and nothing worse will happen to you the rest of the day */

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

#define N 2007

int test;

int n,res1,res2,_res=inf;

VPI pocz[N],kon[N];
int par[N];

set<int>s;

int licz(int b,int a){
    if (b>=a){
        return b-a;
    }else{
        return 24-a+b;
    }
}

int find(int a){
    if (par[a]!=a){
        par[a] = find(par[a]);
    }

    return par[a];
}

void merge(int a,int b){
    par[find(a)] = find(b);
    return;
}

void clean(){
    FOR(i,1,n){
        pocz[i].clear();
        kon[i].clear();
    }

    res1=res2=0;
    _res=inf;

    s.clear();

    return;
}

void solve()
{
    cin >> n;

    clean();

    FOR(i,1,2*n){
        int a = (i+1)/2;
        int b,dep,len;

        cin >> b >> dep >> len;

        pocz[a].eb(dep, i);
        kon[b].eb((dep+len)%24, i);

        res1+=len;
    }

    FOR(j,1,4){
        FOR(i,1,2*n){
            par[i] = i;
        }

        s.clear();res2=0;

        int len1;

        if (j == 1 ){
            len1 = licz( pocz[1][0].st, 0 ) + licz( pocz[1][1].st, kon[1][1].st );

            merge(pocz[1][0].nd,kon[1][0].nd);
            merge(pocz[1][1].nd,kon[1][1].nd);
        }else if (j==2){
            len1 = licz( pocz[1][0].st, 0 ) + licz( pocz[1][1].st, kon[1][0].st );

            merge(pocz[1][0].nd,kon[1][1].nd);
            merge(pocz[1][1].nd,kon[1][0].nd);
        }else if (j==3){
            len1 = licz( pocz[1][1].st, 0 ) + licz( pocz[1][0].st, kon[1][1].st );

            merge(pocz[1][1].nd,kon[1][0].nd);
            merge(pocz[1][0].nd,kon[1][1].nd);
        }else if (j==4){
            len1 = licz( pocz[1][1].st, 0 ) + licz( pocz[1][0].st, kon[1][0].st );

            merge(pocz[1][1].nd,kon[1][1].nd);
            merge(pocz[1][0].nd,kon[1][0].nd);
        }

        res2+=len1;

        FOR(i,2,n){
            int len1 = licz( pocz[i][0].st, kon[i][0].st ) + licz( pocz[i][1].st, kon[i][1].st );
            int len2 = licz( pocz[i][0].st, kon[i][1].st ) + licz( pocz[i][1].st, kon[i][0].st );
        
            if (len1 == len2){
                res2+=len1;

                merge(pocz[i][0].nd,pocz[i][1].nd);
                merge(kon[i][0].nd,kon[i][1].nd);
                merge(kon[i][0].nd,pocz[i][0].nd);
            }else if (len1 < len2){
                res2+=len1;

                merge(pocz[i][0].nd,kon[i][0].nd);
                merge(pocz[i][1].nd,kon[i][1].nd);
            }else{
                res2+=len2;

                merge(pocz[i][0].nd,kon[i][1].nd);
                merge(pocz[i][1].nd,kon[i][0].nd);
            }
        } 

        FOR(i,1,2*n){
            s.insert(find(i));
        }  

        res2+=24*(s.size()-1);

        _res = min(_res,res2);
    }

    cout << _res + res1 << endl;

    return;
}

int32_t main()
{
    boost

    cin >> test;

    FOR(i,1,test)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

  return 0;
}
