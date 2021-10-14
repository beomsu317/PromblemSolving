#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

int board[9][9];
std::vector<std::pair<int, int> > empty_list;

bool isValid(int y, int x, int cand){
    if(board[y][x] != 0) return false;

    for(int i=0;i<9;i++){
        if(cand == board[y][i]) return false;
    }

    for(int i=0;i<9;i++){
        if(cand == board[i][x]) return false;
    }

    int div_y = y/3*3;
    int div_x = x/3*3;
    for(int i=div_y;i<div_y+3;i++){
        for(int j=div_x;j<div_x+3;j++){
            if(cand == board[i][j]) return false;
        }
    }
    return true;
}

void dfs(int idx){
    // std::cout << idx << "\n";
    if(idx == empty_list.size()){
        for(int y=0;y<9;y++){
            for(int x=0;x<9;x++){
                std::cout << board[y][x] << " ";
            }
            std::cout << "\n";
        }
        exit(0);
    }else{
        for(int i=1;i<=9;i++){
            int y = empty_list[idx].first;
            int x = empty_list[idx].second;
            if(isValid(y,x,i)){
                board[y][x]=i;
                dfs(idx+1);
                board[y][x]=0;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    for(int y=0;y<9;y++){
        for(int x=0;x<9;x++){
            std::cin >> board[y][x];
            if(board[y][x] == 0){
                empty_list.push_back(std::make_pair(y,x));
            }
        }
    }

    dfs(0);
    return 0;
}
