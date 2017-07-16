// "policz" function returns sum of phi(i) in range [1,n]
// sito function should be done before running "policz"
// overall complexity is O(N^(2/3))
// define N to around n^(2/3) 

#define int long long
int n;
bitset<N> sit;
int val[N];
unordered_map<int,int>dp;
int pre;

void sito(){
    for(int i=2; i<=pre; i++){
        if (!sit[i]){
            for(int j=i; j<=pre; j+=i){
                sit[j] = 1;
                val[j] /= i;
                val[j] *= i-1;
            }
        }
    }

    FOR(i,1,pre){
        val[i] += val[i-1];
        val[i] %= mod;
    }

    return;
}

int policz(int x){
    if (x <= 0)
        return 0;

    if(dp[x]){
        return dp[x];
    }

    if (x <= N - 7){
        return val[x];
    }

    int kek = x%mod;

    int res = kek * (kek+1) / 2;
    res%=mod;

    for(int i=2; i*i <= x ; i++){
        res -= policz(x/i);
        res+=mod;
        res%=mod;
    }

    for(int i=1; i*i <= x ; i++){
        if (i!=x/i){
            res -= policz(i) * (x/i - x/(i+1));
            res += mod;
            res %= mod;
        }
    }

    res+=mod;
    res%=mod;

    dp[x] = res;

    return res;
}

void solve()
{
    cin >> n;

    pre = min(n,(int)N-7);

    FOR(i,1,pre){
        val[i] = i;
    }

    sito();

    cout << policz(n);

    return;
}