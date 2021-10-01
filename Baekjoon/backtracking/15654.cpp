
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <deque>
#include <unistd.h>

#define MAX 100001
#define INF 1e9

int N, M;
std::vector<int> numbers;
bool visited[10000];

void solve(int cnt, int idx, std::vector<int> &seq){
    if(cnt == M){
        for(int i=0;i<seq.size();i++){
            std::cout << seq[i] << " ";
        }
        std::cout << "\n";
    }else{
        for(int i=idx;i<numbers.size();i++){
            if(visited[i]) continue;
            visited[i] = true;
            seq.push_back(numbers[i]);
            solve(cnt+1, idx, seq);
            seq.pop_back();
            visited[i] = false; 

        }
    }

}

int main(){
    std::cin >> N >> M;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<N;i++){
        int num;
        std::cin >> num;
        numbers.push_back(num);
    };

    sort(numbers.begin(), numbers.end());

    std::vector<int> seq;
    solve(0, 0, seq);
    return 0;
}