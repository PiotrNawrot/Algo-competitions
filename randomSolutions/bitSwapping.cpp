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

#define N (1<<20)
#define M (L+R)/2

int test;

int n,q,cou=1;

struct node{
    int flipped,l,r,val;
}load[N];

void insert(int l,int r,int L = 0,int R = N-1,node &v = load[1]){
    if (r < L || l > R){
        return;
    }

    if (L >= l && R <= r){
        v.flipped ^= 1;
        return;
    }

    if (v.l == 0){
        v.l = ++cou;
    }

    if (v.r == 0){
        v.r = ++cou;
    }

    insert(l,r,L,M,load[v.l]);
    insert(l,r,M+1,R,load[v.r]);

    v.val = 0;

    if (load[v.l].flipped){
        v.val += (R-L+1)/2 - load[v.l].val;
    }else{
        v.val += load[v.l].val;
    }

    if (load[v.r].flipped){
        v.val += (R-L+1)/2 - load[v.r].val;
    }else{
        v.val += load[v.r].val;
    }

    return;
}

int query(int l,int r,int L = 0,int R = N-1,node &v = load[1],int swap = 0){
    if (r < L || l > R){
        return 0;
    }

    if (L >= l && R <= r){
        if (!swap^v.flipped){
            return v.val;
        }else{
            return (R-L+1)-v.val;
        }
    }

    int res = 0;

    if (v.l == 0){
        v.l = ++cou;
    }

    if (v.r == 0){
        v.r = ++cou;
    }

    if (v.l)
        res += query(l,r,L,M,load[v.l],swap^v.flipped);
    if (v.r)
        res += query(l,r,M+1,R,load[v.r],swap^v.flipped);

    return res;
}

void solve()
{
    cin >> n >> q;

    FOR(i,1,q){
        int t,a,b;

        cin >> t >> a >> b;

        if (!t){
            insert(a,b);
        }else{
            cout << query(a,b) << endl;
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
}/* You can't connect the dots looking forward 
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

#define N (1<<20)
#define M (L+R)/2

int test;

int n,q,cou=1;

struct node{
    int flipped,l,r,val;
}load[N];

void insert(int l,int r,int L = 0,int R = N-1,node &v = load[1]){
    if (r < L || l > R){
        return;
    }

    if (L >= l && R <= r){
        v.flipped ^= 1;
        return;
    }

    if (v.l == 0){
        v.l = ++cou;
    }

    if (v.r == 0){
        v.r = ++cou;
    }

    insert(l,r,L,M,load[v.l]);
    insert(l,r,M+1,R,load[v.r]);

    v.val = 0;

    if (load[v.l].flipped){
        v.val += (R-L+1)/2 - load[v.l].val;
    }else{
        v.val += load[v.l].val;
    }

    if (load[v.r].flipped){
        v.val += (R-L+1)/2 - load[v.r].val;
    }else{
        v.val += load[v.r].val;
    }

    return;
}

int query(int l,int r,int L = 0,int R = N-1,node &v = load[1],int swap = 0){
    if (r < L || l > R){
        return 0;
    }

    if (L >= l && R <= r){
        if (!swap^v.flipped){
            return v.val;
        }else{
            return (R-L+1)-v.val;
        }
    }

    int res = 0;

    if (v.l == 0){
        v.l = ++cou;
    }

    if (v.r == 0){
        v.r = ++cou;
    }

    if (v.l)
        res += query(l,r,L,M,load[v.l],swap^v.flipped);
    if (v.r)
        res += query(l,r,M+1,R,load[v.r],swap^v.flipped);

    return res;
}

void solve()
{
    cin >> n >> q;

    FOR(i,1,q){
        int t,a,b;

        cin >> t >> a >> b;

        if (!t){
            insert(a,b);
        }else{
            cout << query(a,b) << endl;
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