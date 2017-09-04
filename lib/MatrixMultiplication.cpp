// Struct for matrix multiplication 
// and fast pow for matrix multiplication
// Complexity O(M^3*log(k))
// where M is size of matrix and k is our exponent

struct matrix{
    int t[M][M];

    matrix operator*(matrix b){
        matrix c;

        for(int i=0; i<M; i++){
            for(int j=0; j<M; j++){
                c.t[i][j] = 0;
            }
        }

        for(int i=0; i<M; i++){
            for(int k=0; k<M; k++){
                for(int j=0; j<M; j++){
                    c.t[i][j] += t[i][k] * b.t[k][j];
                    c.t[i][j] %= mod;
                }
            }
        }

        return c;
    }
};

matrix base;

matrix zrob(int pot){
    if (pot == 1){
        return base;
    }

    if (pot%2 == 0){
        matrix c = zrob(pot/2);

        return c*c;
    }

    if (pot%2 == 1){
        matrix c = zrob(pot/2);

        return c*c*base;
    }

    return base;
}