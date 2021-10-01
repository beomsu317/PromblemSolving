#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string N;
    std::cin >> N;
    std::vector<int> numbers;

    for(int i=0;i<N.size();i++){
        // std::cout << N[i] << "\n";
        numbers.push_back(N[i]-0x30);
    }

    sort(numbers.begin(), numbers.end());
    std::reverse(numbers.begin(),numbers.end());

    for(int i=0;i<numbers.size();i++){
        std::cout << numbers[i];
    }
    std::cout << "\n";

    return 0;
}
