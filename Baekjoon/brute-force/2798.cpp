#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9
#define MAX 100001

int main()
{
    int N=5, M=21;
    int value = INF;
    int result = 0;
    std::cin >> N >> M;
    std::vector<int> numbers;
    for(int i=0;i<N;i++){
        int tmp;
        std::cin >> tmp;
        numbers.push_back(tmp);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(i!=j && j!=k && k!=i){
                    int sum = (numbers[i] + numbers[j] + numbers[k]);
                    if(std::abs(M - sum) < value && sum <= M){
                        value = std::min(value, std::abs(M - sum));
                        result = sum;
                    }
                }
            }
        }
    }
    std::cout << result << "\n";
    return 0;
}
