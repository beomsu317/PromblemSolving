#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <deque>
#include <unistd.h>

#define MAX 100001
#define INF 1e9

int N, M;
bool visited[10];
std::vector<int> result;


void solve(int cnt,int idx){
    // std::cout << "idx: "<<idx << "\n";
    if(cnt == M){
        for(int i=0;i<M;i++){
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }else{
        for(int i=1;i<=N;i++){
            if(idx > i) continue;
            if(visited[i]) continue;
            visited[i] = true;
            result.push_back(i);
            solve(cnt+1, i);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    std::cin >> N >> M; 
    memset(visited,false,sizeof(visited));
    solve(0,1);
    return 0;
}