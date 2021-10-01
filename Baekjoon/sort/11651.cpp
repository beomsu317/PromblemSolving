#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9

bool compare(std::pair<int, int> point1, std::pair<int, int> point2){
    if(point1.second == point2.second){
        return point1.first < point2.first;
    }else{
        return point1.second < point2.second;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::pair<int, int> > points;
    for(int i=0;i<N;i++){
        int x,y;
        std::cin >> x >> y;
        points.push_back(std::make_pair(x,y));
    }

    sort(points.begin(), points.end(), compare);
    for(int i=0;i<points.size();i++){
        std::cout << points[i].first << " " << points[i].second << "\n";
    }

    return 0;
}
