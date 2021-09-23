// https://www.acmicpc.net/problem/11444
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9
#define MOD 1000000007

typedef std::vector<std::vector<long long> > Matrix;

void printMatrix(Matrix a){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            std::cout << "["<<i<<"]["<<j<<"]: " << a[i][j] << "\n";
        }
    }
    std::cout << "\n";
}

Matrix mul(Matrix a, Matrix b){
    Matrix matrix(2);
    matrix[0].resize(2);
    matrix[1].resize(2);
    matrix[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
    matrix[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
    matrix[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
    matrix[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
    return matrix;
}

Matrix divideAndConquer(Matrix matrix,long long n){
    if(n == 1)
        return matrix;

    // divide
    matrix = divideAndConquer(matrix, n/2);
    // conquer
    matrix = mul(matrix, matrix);
    // In case of odd numbers, multiply once more.
    if(n % 2 == 1){
        Matrix b(2);
        b[0].resize(2);
        b[1].resize(2);
        b[0][0] = 1;
        b[0][1] = 1;
        b[1][0] = 1;
        b[1][1] = 0;
        matrix = mul(matrix, b);
    }

    return matrix;
}

long long fibo(long long n){
    Matrix init(2);
    init[0].resize(2);
    init[1].resize(2);
    init[0][0] = 1;
    init[0][1] = 1;
    init[1][0] = 1;
    init[1][1] = 0;

    return divideAndConquer(init, n)[0][1];
}

int main()
{
    long long n;
    std::cin >> n;
    std::cout << fibo(n) << "\n";
    return 0;
}