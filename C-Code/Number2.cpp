#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;
vector<long long> V;
vector<char> C;
char arr[6][3] = {{'*','+','-'},{'*','-','+'},{'+','*','-'},{'+','-','*'},{'-','*','+'},{'-','+','*'}};
string s1 = "100-200*300-500+20";
void Sparse(string ex){
    int size = ex.size();
    string num="";
    string oper="";
    for(int i=0;i<size;i++){
        if(ex[i] >='0' && ex[i] <= '9'){
            num += ex[i];
            if(i==0) continue;
        }
        else{
            V.push_back(atoi(num.c_str()));
            C.push_back(ex[i]);
            num = "";
        }
        if(i==size-1){
          V.push_back(atoi(num.c_str()));
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    Sparse(expression);
    vector<long long> tempV;
    vector<char> tempC;
    cout<<V.size()<<" "<<C.size()<<'\n';
    for(int i=0;i<6;i++){
        tempV = V;
        tempC = C;
        for(int j=0;j<3;j++){
            for(int k = 0;k <tempC.size();k++){
                if(tempC[k] == arr[i][j]){
                    if(tempC[k] == '-'){
                        tempV[k] = tempV[k]-tempV[k+1];
                        tempV.erase(tempV.begin()+k+1);
                        tempC.erase(tempC.begin()+k);
                        k--;
                    }else if(tempC[k] == '+'){
                        tempV[k] = tempV[k]+tempV[k+1];
                        tempV.erase(tempV.begin()+k+1);
                        tempC.erase(tempC.begin()+k);
                        k--;
                    }else if(tempC[k] == '*'){
                        tempV[k] = tempV[k]*tempV[k+1];
                        tempV.erase(tempV.begin()+k+1);
                        tempC.erase(tempC.begin()+k);
                        k--;
                    }
                }
            }
        }
        answer = max(abs(tempV[0]),answer);
    }
    return answer;
}

int main(){
  cout<<solution(s1);
  return 0;
}
