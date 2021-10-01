#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
#include <vector>

#define INF 1e9

int main()
{
    int N;
    int cnt[10001] = {0,};
    
    std::cin >> N;
    for(int i=0;i<N;i++){
        int num;
        std::cin >> num;
        cnt[num]++;
    }

    for(int i=1;i<10001;i++){
        if(cnt[i] == 0) continue;
        for(int j=0;j<cnt[i];j++){
            std::cout << i << "\n";
        }
    }
    return 0;
}