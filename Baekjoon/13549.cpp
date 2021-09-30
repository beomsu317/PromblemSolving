#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
#include <queue>

#define MAX 100001
#define INF 1e9

int N,K;

int bfs(){
    int visited[MAX];
    for(int i=0;i<MAX;i++){
        visited[i] = INF;
    }
    
    std::queue<int> q;
    q.push(N);
    visited[N] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == K)
            return visited[K];

        if(current + 1 < MAX && visited[current + 1] > visited[current] + 1){
            visited[current + 1] = visited[current] + 1;
            q.push(current + 1);
        }
        if(current - 1 >= 0 && visited[current - 1] > visited[current] + 1){
            visited[current - 1] = visited[current] + 1;
            q.push(current - 1);
        }
        if(current * 2 < MAX && visited[current * 2] > visited[current]){
            visited[current * 2] = visited[current];
            q.push(current * 2);
        }
    }
    return 0;
}

int main(){
    std::cin >> N >> K; 
    std::cout << bfs() << "\n";
    return 0;
}