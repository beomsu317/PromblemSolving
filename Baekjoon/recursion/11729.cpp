#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <deque>
#include <unistd.h>

#define MAX 100001
#define INF 1e9

std::vector<std::pair<int,int> > result;

void hanoi(int n, int from, int by, int to){
    if(n==0) return;
    hanoi(n-1, from, to, by);
    result.push_back(std::make_pair(from,to));
    hanoi(n-1, by, from, to);
}

int main(){
    int N;
    std::cin >> N;
    hanoi(N, 1, 2, 3);
    std::cout << result.size() << "\n";
    for(int i=0;i<result.size();i++){
        std::cout << result[i].first << " " << result[i].second << "\n";
    }
    return 0;
}