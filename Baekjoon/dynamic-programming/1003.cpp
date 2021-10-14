#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

int T;
int dp[41];

int fibonacci(int n) {
    if(dp[n] != -1){    
        return dp[n];
    }
    
    int &ret = dp[n];

    if (n == 0) {
        ret = 0;
    } else if (n == 1) {
        ret = 1;
    } else {
        ret = fibonacci(n-1) + fibonacci(n-2);
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    std::cin >> T;
    int num;
    while(T--){
        std::cin >> num;
        fibonacci(num);
        // std::cout << fibo << "\n";
        if(num == 0){
            std::cout << "1 0" << "\n";
        }else{
            std::cout << dp[num-1] << " " << dp[num] << "\n";
        }
    }

    return 0;
}
