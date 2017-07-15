int n,m,a,b,s,t,sum,cou;

PII st,kon;

int grid[N][N];

int nr[N][N];

int lvl[N*N];

queue<int>q;

VI g[N*N];

int cap[N*N][N*N];

bool bfs(){
    q.push(s);
    FOR(i,0,2*sum){
        lvl[i] = -1;
    }
    lvl[s]=0;

    while(!q.empty()){
        auto v = q.front();
        q.pop();

        for(auto it:g[v]){
            if ( lvl[it] == -1 && cap[v][it] > 0 ){
                lvl[it] = lvl[v] + 1;
                q.push(it);
            }
        }
    }

    return lvl[t]!=-1;
}

int dfs(int v,int val){
    if (v == t || val == 0){
        return val;
    }

    int res = 0;

    for(auto it:g[v]){
        if ( lvl[it] == lvl[v] + 1 && cap[v][it] > 0 ){
            int kek = dfs( it, min(val, cap[v][it] ) );
            
            res += kek;
            val -= kek;

            cap[v][it] -= kek;
            cap[it][v] += kek;

            if (val == 0){
                return res;
            }
        }
    }

    return res;
}

int dinic(){
    int max_flow = 0;

    while(bfs()){
        max_flow += dfs(s,inf);
    }

    return max_flow;
}
