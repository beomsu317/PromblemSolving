// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9
#define MAX 101
int n,m;
int dp[MAX][MAX];

int main()
{
    std::cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = INF;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,cost;
        std::cin >> a >> b >> cost;
        // std::cout << "a: "<< a << ", b:" << b << ", cost: " << cost << "\n";
        dp[a][b] = std::min(dp[a][b], cost);
        // std::cout << "a: "<< a<<", b: "<< b<<", cost: "<< dp[a][b] << "\n";
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j || dp[i][j] == INF)
                std::cout << "0";
            else
                std::cout << dp[i][j];
            
            
            if(j != n)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}