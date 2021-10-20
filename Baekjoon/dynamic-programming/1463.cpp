#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <unistd.h>

#define INF 1e9

int dp[1000001];

int N;

int solve(int num){
    if(num == 1) {
        return 0;
    }
    int &ret = dp[num];
    if(ret != -1){
        return ret;
    } 
    ret = solve(num - 1) + 1;
    if(num % 2 == 0) ret = std::min(ret, solve(num/2) + 1);
    if(num % 3 == 0) ret = std::min(ret, solve(num/3) + 1);
    return ret;

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    std::cin >> N;
    std::vector<int> path;
    std::cout << solve(N) << "\n";
    return 0;
}
