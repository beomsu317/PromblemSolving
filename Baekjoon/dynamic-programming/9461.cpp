#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <unistd.h>

#define INF 1e9

long long dp[101];

long long padovan(int N){
    if(N==1 || N==2 || N==3) return 1;
    else if(N==4 || N==5) return 2;
    else if(N==6) return 3;
    else if(N==7) return 4;
    else if(N==8) return 5;
    else if(N==9) return 7;
    else if(N==10) return 9;
    
    if(dp[N] != -1) return dp[N];
    long long &ret = dp[N];
    return ret = padovan(N-5) + padovan(N-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::cin >> N;
        std::cout << padovan(N) << "\n";
    }

    return 0;
}
