#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>
#include <set>
#include <map>

#define INF 1e9

typedef struct triple{
    int ori_idx=0;
    int idx=0;
} Triple;

bool compare(std::pair<int,Triple> &item1, std::pair<int,Triple> &item2){
    return item1.first > item2.first;
}

bool idxCompare(std::pair<int,Triple> &item1, std::pair<int,Triple> &item2){
    return item1.second.ori_idx < item2.second.ori_idx;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::pair<int,Triple> > numbers;
    for(int i=0;i<N;i++){
        int tmp;
        std::cin >> tmp;
        Triple tri;
        tri.ori_idx = i;
        numbers.push_back(std::make_pair(tmp,tri));
    }
    
    sort(numbers.begin(),numbers.end(), compare);
    std::reverse(numbers.begin(), numbers.end());

    int idx = 0;
    std::map<int,int> store;
    for(int i=0;i<numbers.size();i++){
        std::map<int,int>::iterator val = store.find(numbers[i].first);
        if(val != store.end()){
            numbers[i].second.idx = (*val).second;
            continue;
        }

        numbers[i].second.idx = idx;
        store.insert(std::make_pair(numbers[i].first, idx));
        idx++;
    }
    
    sort(numbers.begin(),numbers.end(), idxCompare);
    
    for(int i=0;i<numbers.size();i++){
        // std::cout << numbers[i].first << ", " << numbers[i].second.ori_idx << ", " << numbers[i].second.idx << "\n";
        std::cout << numbers[i].second.idx << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
5
2 4 -10 4 -9

6
1000 999 1000 999 1000 999
*/