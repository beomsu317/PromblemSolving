#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

int N;
int operations[4];
long long max_val = -1000000001, min_val = 1000000001;
int seq[12];

void solve(int idx, long long value){
    // std::cout << idx << "\n";
    if(idx == N){
        if(value > max_val) max_val = value;
        if(value < min_val) min_val = value;
        return;
    }

    for(int i=0;i<4;i++){
        if(operations[i]>0){
            operations[i]--;
            if(i==0) solve(idx+1,value + seq[idx]);
            else if(i==1) solve(idx+1,value - seq[idx]);
            else if(i==2) solve(idx+1,value * seq[idx]);
            else if(i==3) solve(idx+1,value / seq[idx]);
            operations[i]++;
        }
    }   
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;
    for(int i=0;i<N;i++){
        std::cin >> seq[i];
    }    

    for(int i=0;i<4;i++){
        std::cin >> operations[i];
    }

    solve(1,seq[0]);

    std::cout << max_val <<"\n" << min_val << "\n";

    return 0;
}
