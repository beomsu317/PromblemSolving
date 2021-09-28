#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 


int N, K;
std::vector<std::pair<int, int> > item;
int dp[100001][101];
int max=0;

int solve(int capacity, int idx){
    if(idx >= item.size()) return 0;
    int &ret = dp[capacity][idx];
    if(ret != -1){
        return ret;
    }

    // If you don't put item in backpack
    ret = solve(capacity, idx + 1);
    if(capacity >= item[idx].first){
        // If you put item in backpack
        int put = solve(capacity - item[idx].first, idx + 1);
        ret = std::max(ret, put + item[idx].second);
    }
    return ret;
}

int main(){
    std::cin >> N >> K;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        int W, V;
        std::cin >> W >> V;
        item.push_back(std::make_pair(W,V));
    }

    std::cout << solve(K,0) << "\n";

    return 0;
}