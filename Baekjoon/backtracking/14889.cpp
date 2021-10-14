#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

int N;
int board[21][21];
bool used[21];
int min_value = 987654321;

void dfs(int cnt, int player){
    if(cnt == N/2){
        std::vector<int> start;
        std::vector<int> link;
        for(int i=0;i<N;i++){
            if(used[i]) start.push_back(i);
            else link.push_back(i);
        }
        int link_sum = 0;
        int start_sum = 0;
        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                start_sum += board[start[i]][start[j]];
                link_sum += board[link[i]][link[j]];
            }
        }
        min_value = std::min(min_value, std::abs(link_sum - start_sum));
        return;
    }

    std::cout << player << "\n";
    for(int i=player+1;i<N;i++){
        used[i] = true;
        dfs(cnt+1, i);
        used[i] = false;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    memset(used,0,sizeof(used));

    std::cin >> N;
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            std::cin >> board[y][x];
        }
    }

    dfs(0,0);

    std::cout << min_value << "\n";

    return 0;
}
