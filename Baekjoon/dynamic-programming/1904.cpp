#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <unistd.h>

#define INF 1e9

int N;
int dp[1000001];

int tile(int num){
    if(num == 1) return 1;
    if(num == 2) return 2;

    if(dp[num] != -1) return dp[num];
    int &ret = dp[num];
    return ret = (tile(num-2) + tile(num-1)) % 15746;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    memset(dp, -1, sizeof(dp));
    std::cout << tile(N) << "\n";

    return 0;
}
