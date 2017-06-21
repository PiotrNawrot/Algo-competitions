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

#define N 1000007
#define M 30

int test;

int n;

int trie[N][M];
int fail[N];
VI val[N];
int res[N];

int cou = 1,alph = 26;

void add(string s,int nr){
    int n = s.length(), v = 1;

    for(int i = 0; i<n; i++){
        int to = s[i] - 'a' + 1;

        if (trie[v][to]){
            v = trie[v][to];
        }else{
            v = trie[v][to] = ++cou;
        }
    }

    val[v].pb(nr);

    return;
}

void init(){
    queue<int>q;
    int v = 1;
    
    for(int i=1; i<=alph; i++){
        if (trie[v][i]){
            fail[trie[v][i]] = v;
            q.push(trie[v][i]);
        }
    }

    while(!q.empty()){
        v = q.front(); q.pop();

        for(int i=1; i<=alph; i++){
            if (trie[v][i]){
                int u = trie[v][i];
                int j = fail[v];

                while(trie[j][i] == 0 && j>1){
                    j = fail[j];
                }

                fail[u] = trie[j][i] ? trie[j][i] : 1;

                for(auto it:val[fail[u]]){
                    val[u].pb(it);
                }

                q.push(u);
            }
        }
    }

    return;
}

void query(string s){
    int n = s.length(), v=1;

    for(int i=0; i<n; i++){
        int to = s[i] - 'a' + 1;

        while(trie[v][to] == 0 && v > 1){
            v = fail[v];
        }

        v = trie[v][to] ? trie[v][to] : 1; 

        while(val[v].size()){
            res[val[v].back()]=1;
            val[v].pop_back();
        }
    }

    return;
}

void solve()
{
    string s;
    cin >> s;

    cin >> n;

    FOR(i,1,n){
        string ss;
        cin >> ss;
        
        add(ss,i);
    }

    query(s);

    FOR(i,1,n){
        cout << ((res[i]) ? ("Y") : ("N")) << endl;
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
