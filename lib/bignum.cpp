#define N 10007

string s;

struct bignum{
    int l; // length of the number
    int arr[N]; // the number itself

    bignum operator*(const bignum a){
        bignum b;

        for(int i=1; i<=a.l; i++){
            for(int j=1; j<=l; j++){
                b.arr[i+j-1] += a.arr[i] * arr[j];
            }
        }

        int i = 1,tran = 0;
        
        while(1){
            if (tran == 0 && b.arr[i] == 0){
                break;
            }

            b.arr[i] += tran;
            tran = b.arr[i] / 10;
            b.arr[i] %= 10;

            i++;
        }   

        b.l = i-1;

        return b;
    }
};

void solve()
{
    bignum a,b;

    cin >> a.l >> b.l;

    cin >> s;reverse(s.begin(),s.end());

    FOR(i,1,a.l){
        a.arr[i] = s[i-1] - '0';
    }

    cin >> s;reverse(s.begin(),s.end());

    FOR(i,1,b.l){
        b.arr[i] = s[i-1] - '0';
    }

    bignum c = a*b;

    FORR(i,c.l,1){
        cout << c.arr[i];
    }

    return;
}