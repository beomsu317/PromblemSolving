#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 

int count = 0;
int n;
int board[15];

bool possible(int row){
    for(int i=0;i<row;i++){
        if(board[row] == board[i] || row - i == abs(board[row] - board[i]))
            return false;
    }
    return true;
}

void solve(int row){
    if(row == n){
        count++;
    } else {
        for(int col=0;col<n;col++){
            board[row] = col;
            if(possible(row))
                solve(row+1);
        }
    }
}

int main()
{
    std::cin >> n;
    solve(0);
    std::cout << count << "\n";

    return 0;
}