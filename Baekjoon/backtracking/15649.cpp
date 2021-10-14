#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

int N, M;
bool visited[8 + 1];

void print(std::vector<int> &seq,int idx){
    if(seq.size() == M){
        for(int i=0;i<seq.size();i++){
            std::cout << seq[i] << " ";
        }
        std::cout << "\n";
        return;
    }else{
        for(int i=1;i<=N;i++){
            if(visited[i]) continue;
            visited[i] = true;
            seq.push_back(i);
            print(seq,i);
            seq.pop_back();   
            visited[i] = false;
        }
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    memset(visited,0,sizeof(visited));
    std::vector<int> seq;
    print(seq,1);

    return 0;
}

/*
3 1
*/