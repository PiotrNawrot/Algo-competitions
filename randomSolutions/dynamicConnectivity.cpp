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

#define N (1<<20)
#define M (L+R)/2

int test;

int n,k;

PII edg[2*N+700];

int in[2*N+700],out[2*N+700];

int query[N*2+700],odp[N*2+700],res[N*2+700],ile[N*2+700];

int cou;

map<PII,int>m;

VI load[2*N+700];

int p[2*N+700],rnk[2*N+700];

vector<pair<int,PII>> changes;

int wyn = 0;

void insert(int id,int l,int r,int v = 1,int L = 1,int R = N){
	if (L > r || R < l || L > R){
		return;
	}

	if (L >= l && R <= r){
		load[v].pb(id);
		return;
	}

	if (L == R){
		return;
	}

	insert(id,l,r,v*2,L,M);
	insert(id,l,r,v*2+1,M+1,R);

	return;
}

int findP(int x){
	if (x != p[x]){
		return findP(p[x]);
	}

	return p[x];
}

bool merge(int x,int y){
	x = findP(x);
	y = findP(y);

	if (x == y){
		return 0;
	}else{
		if (rnk[x] > rnk[y]){
			changes.eb(y,mp(x,0));

			p[y] = x;
		}else{
			p[x] = y;

			if (rnk[x] == rnk[y]){
				rnk[y]++;

				changes.eb(x,mp(y,1));
			}else{
				changes.eb(x,mp(y,0));
			}
		}

		return 1;
	}
}

void dfs(int v){
	for(auto it:load[v]){
		if (merge(edg[it].st,edg[it].nd)){
			ile[v]++;
			wyn--;
		}
	}

	if (v >= N){
		if (query[v-N+1])
			res[v-N+1] = wyn;
	}else{
		dfs(v*2);
		dfs(v*2+1);

		// debug(v,ile[v],wyn);
	}

	while(ile[v]>0){
		wyn++;
		ile[v]--;

		auto it = changes.back();

		p[it.st] = it.st;
		rnk[it.nd.st] -= it.nd.nd;

		changes.pop_back();
	}

	return;
}

int main()
{
	#define NAME "connect"
  	assert(freopen(NAME ".in", "r", stdin));
  	assert(freopen(NAME ".out", "w", stdout));

	scanf("%d%d",&n,&k);

	FOR(i,1,n){
		p[i] = i;
	}

	wyn = n;

	FOR(i,1,k){
		char c;
		scanf(" %c", &c);

		if (c == '?'){
			query[i] = 1;
		}else if (c == '+'){
			int a,b;
			scanf("%d%d", &a, &b);

			edg[++cou] = mp(a,b);
			m[mp(a,b)] = cou;
			in[cou] = i;
		}else if (c == '-'){
			int a,b;
			scanf("%d%d", &a, &b);

			int nr = m[mp(a,b)];

			if (nr == 0){
				swap(a,b);
				nr = m[mp(a,b)];
			}

			m[mp(a,b)] = 0;
			out[nr] = i;
		}
	}

	FOR(i,1,cou){
		if (out[i] == 0){
			out[i] = k;
		}

		insert(i,in[i],out[i]);
	}

	dfs(1);

	FOR(i,1,k){
		if (query[i] == 1){
			printf("%d\n", res[i]);
		}
	}

    return 0;
}
