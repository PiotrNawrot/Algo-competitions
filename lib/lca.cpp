// Algorithm for finding lowest common ancestor in rooted tree
// Complexity O(logn)

int root = 1;

int dp[N][LOG],h[N];

void dfs(int v,int prev){
    dp[v][0] = prev;
    h[v] = h[prev] + 1;

    REP(i,g[v].size()){
        int it = g[v][i];
        if (it!=prev){
            dfs(it,v);
        }
    }

    return;
};

void init(){
	dfs(root,0);

    FOR(i,1,LOG-1){
        FOR(j,1,n){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
};

int lca(int x,int y){
    if (h[x] < h[y]){
        swap(x,y);
    }

    FORR(i,LOG-1,0){
        if ( h[x] - (1<<i) >= h[y] ){
            x = dp[x][i];
        }
    }

    if (x==y){
        return y;
    }

    FORR(i,LOG-1,0){
        if (dp[x][i]!=dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }

    return dp[x][0];
};