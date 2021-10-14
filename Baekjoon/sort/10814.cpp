#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9

bool compare(std::pair<int, std::pair<int, std::string> > user1, std::pair<int, std::pair<int, std::string> > user2){
    if(user1.second.first != user2.second.first){
        return user1.second.first < user2.second.first;
    }else{
        return user1.first < user2.first;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::pair<int, std::pair<int, std::string> > > users;
    for(int i=0;i<N;i++){
        int age;
        std::string name;
        std::cin >> age >> name;
        users.push_back(std::make_pair(i, std::make_pair(age,name)));
    }

    sort(users.begin(), users.end(), compare);
    for(int i=0;i<users.size();i++){
        std::cout << users[i].second.first << " " << users[i].second.second << "\n";
    }

    return 0;
}
