#include <string>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;
vector<string> V;
int solution(int cacheSize, vector<string> cities) {
    int size = cities.size(),count = 0;
    int answer = 0;
    char temp;
    if(cacheSize == 0) return 5*cities.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<cities[i].size();j++)
            if(cities[i][j] >='a') cities[i][j] -= 32;
        int check =0;
        for(int j=0;j<V.size();j++){
            if(cities[i] == V[j]){
                V.erase(V.begin()+j);
                V.push_back(cities[i]);
                answer++;
                check=1;
                break;
            }
        }
        if(check ==0){
            answer +=5;
            if(count>=cacheSize){
                V.erase(V.begin());
                V.push_back(cities[i]);
            }else{
                V.push_back(cities[i]);
                count++;
            }
        }
    }
    return answer;
}
