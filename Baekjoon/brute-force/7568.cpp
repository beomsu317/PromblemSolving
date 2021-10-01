#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9
#define MAX 100001

int main()
{
    int N;
    std::vector<std::pair<int,int> > persons;
    int result[51] = {0,};
    
    std::cin >> N;
    for(int i=0;i<N;i++){
        int weight, tall;
        std::cin >> weight >> tall;
        persons.push_back(std::make_pair(weight,tall));
    }

    int idx = 0;
    for(int i=0;i<persons.size();i++){
        int num=0;
        for(int j=0;j<persons.size();j++){
            if(i!=j){
                if(persons[i].first < persons[j].first && persons[i].second < persons[j].second){
                    num++;
                }
            }
        }
        std::cout << num+1 << "\n";
    }

    return 0;
}

