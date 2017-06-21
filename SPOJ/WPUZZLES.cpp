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
#define M 40

int test;
int n,m,k,alph = 30;

int trie[N][M];
int fail[N];
VPI val[N];

struct res{
    int x,y;
    char dir;
}res[N];

string grid[N];
int cou = 1;

void add(string s,int nr){
    int n = s.length(), v = 1;

    for(int i = 0; i<n; i++){
        int to = s[i] - 'A' + 1;

        if (trie[v][to]){
            v = trie[v][to];
        }else{
            v = trie[v][to] = ++cou;
        }
    }

    val[v].eb(nr,n);

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

int sub_x[] = {0,1,1,1,0,-1,-1,-1};
int sub_y[] = {-1,-1,0,1,1,1,0,-1};

void query(int x,int y,int dir){
    int v=1;

    while(x >= 1 && x <= n && y >= 1 && y <= m){
        int to = grid[x][y] - 'A' + 1;

        while(trie[v][to] == 0 && v > 1){
            v = fail[v];
        }

        v = trie[v][to] ? trie[v][to] : 1; 

        while(val[v].size()){
            auto it = val[v].back();
            val[v].pop_back();

            res[it.st].dir = (char)('A'+dir);
            res[it.st].x = x - (it.nd - 1) * sub_y[dir];
            res[it.st].y = y - (it.nd - 1) * sub_x[dir];
        }

        x+=sub_y[dir];y+=sub_x[dir];
    }

    return;
}

void solve()
{
    cin >> n >> m >> k;

    FOR(i,1,n){
        cin >> grid[i];
        grid[i] = '#' + grid[i];
    }

    FOR(i,1,k){
        string word;
        cin >> word;
        add(word,i);
    }

    init();

    FOR(i,1,n){
        REP(j,8){
            query(i,1,j);
            query(i,m,j);
        }
    }

    FOR(i,1,m){
        REP(j,8){
            query(1,i,j);
            query(n,i,j);
        }
    }

    FOR(i,1,k){
        cout << res[i].x-1 << " " << res[i].y-1 << " " << res[i].dir << endl;
        res[i].x = res[i].y = res[i].dir = 0;
    }

    FOR(i,1,cou){
        fail[i]=0;
        val[i].clear();
        grid[i].clear();
        FOR(j,1,26){
            trie[i][j]=0;
        }
    }

    cou=1;

    return;
}

int32_t main()
{
    boost

    cin >> test;

    while(test--)
    {
        solve();
        cout << endl;
    }

  return 0;
}
