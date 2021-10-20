#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>
#include <unistd.h>

#define INF 1e9

int dp[101][101][101];

int w(int a, int b, int c){
    // std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";
    if(dp[a+50][b+50][c+50] != -1) return dp[a+50][b+50][c+50];
    int &ret = dp[a+50][b+50][c+50];
    // sleep(1);
    if(a<=0 || b<=0 || c<=0) return ret = 1;
    if(a>20 || b>20 || c>20) return ret = w(20,20,20);
    if(a<b && b<c){
        ret = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }
    else{
        ret = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int a, b, c;
    while(true){
        std::cin >> a >> b >> c;        
        if(a==-1 && b==-1 && c==-1) break;
        std::cout << "w("<<a<<", "<<b<<", " <<c<<") = " << w(a,b,c) << "\n";
    }


    return 0;
}
