#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <unistd.h>

#define INF 1e9

int dp[301];

int N;
int stairs[301];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    memset(dp, -1, sizeof(dp));

    for(int i=0;i<N;i++){
        std::cin >> stairs[i];
    }

    // std::vector<int> path;
    // std::cout << std::max(solve(0,0,0,path), solve(1,0,0,path)) << "\n";

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = std::max(stairs[0],stairs[1]) + stairs[2];

    for(int i=3;i<N;i++){
        dp[i] = std::max(dp[i-3] + stairs[i-1], dp[i-2]) + stairs[i];
    }
    std::cout << dp[N-1] << "\n";

    return 0;
}
