#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9

int board[1025][1025];
int n, m;

int main()
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num;
            std::cin >> num;
            board[i][j] = board[i][j-1] + board[i-1][j] - board[i-1][j-1] + num;
        }
    }
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        std::cin >> y1 >> x1 >> y2 >> x2;
        std::cout << board[y2][x2] - board[y2][x1-1] - board[y1-1][x2] + board[y1-1][x1-1] << "\n";
    }

    return 0;
}