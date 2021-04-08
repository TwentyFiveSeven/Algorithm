#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0,size = skill_trees.size(),sizeN,count=0,sizek = skill.size(),flag;

    for(int i = 0;i<size;i++){
        sizeN = skill_trees[i].size();
        for(int j=0;j<sizeN;j++){
            flag = 0;
            for(int k=0;k<sizek;k++){
                if(skill[k] == skill_trees[i][j]){
                    if(k!=0&& arr[k-1] == 0){
                        flag = 1;
                        break;
                    }else{
                        arr[k] = 1;
                        break;
                    }
                }
            }
            if(flag ==1)
                break;
        }
        if(flag!=1){
            answer++;
        }
        for(int j=0; j<sizeN;j++)
            arr[j] = 0;
    }
    return answer;
}
