// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9
#define N 100001

int n;
std::vector<int> tree[N];
bool visited[N];
int ans[N];

// DFS를 통해 모든 루트 노드를 구한다.
void dfs(int idx){
    visited[idx] = true;
    for(int i=0;i<tree[idx].size();i++){
        if(!visited[tree[idx][i]]){
            ans[tree[idx][i]] = idx;   
            dfs(tree[idx][i]);
        }
    }
}

int main()
{
    memset(visited,0,sizeof(visited));
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    for(int i=0;i<n-1;i++){
        int node1,node2;
        std::cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    dfs(1);

    for(int i=2;i<=n;i++){
        std::cout << ans[i] << "\n";
    }


    return 0;
}