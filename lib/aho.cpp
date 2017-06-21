// Aho-corasick algorithm
// Complexity O(n + m + z) where 
// n - length of patterns
// m - length of text
// z - number of occurences of patterns in the text
// add function adds new pattern
// init function initializes failure edges
// query function outputs for given text
// number of ocurences of all patterns in this text

// N - number of all characters in patterns
// M - size of alphabet

int trie[N][M];
int fail[N];
int val[N];

int cou = 1,alph = 26;

void add(string s){
    int n = s.length(), v = 1;

    for(int i = 0; i<n; i++){
        int to = s[i] - 'a' + 1;

        if (trie[v][to]){
            v = trie[v][to];
        }else{
            v = trie[v][to] = ++cou;
        }
    }

    val[v]++;

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

                val[u]+=val[fail[u]];

                q.push(u);
            }
        }
    }

    return;
}

int query(string s){
    int res = 0, n = s.length(), v=1;

    for(int i=0; i<n; i++){
        int to = s[i] - 'a' + 1;

        while(trie[v][to] == 0 && v > 1){
            v = fail[v];
        }

        v = trie[v][to] ? trie[v][to] : 1; 

        res+=val[v];
    }

    return res;
}