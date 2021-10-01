#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <deque>
#include <unistd.h>

#define MAX 100001
#define INF 1e9

void star(int y, int x,int n){
    if((y/n)%3 == 1 && (x/n)%3 == 1){
        std::cout << " ";
    }else{
        if(n/3 == 0) 
            std::cout << "*";
        else 
            star(y, x, n/3);
    }
}

int main(){
    int N;
    std::cin >> N;
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++) 
            star(y,x,N);
        std::cout << "\n";  
    }
    return 0;
}