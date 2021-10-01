#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 

using namespace std;

int n;
int sticker[2][100001];
int dp[2][100001];

int solve(){

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[0][1] + dp[1][0];
    dp[1][1] = sticker[1][1] + dp[0][0];

    for(int i=2;i<=n;i++){
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
    }
    
    return max(dp[0][n],dp[1][n]);
}

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        memset(sticker,0,sizeof(sticker));
        memset(dp,-1,sizeof(dp));
        cin >> n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> sticker[i][j];
            }
        }
        cout << solve() << "\n";
    }

    return 0;
}